#pragma once

#include <condition_variable>
#include <functional>
#include <future>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>
#include <vector>

class ThreadPool
{
public:
  /**
   * @brief Construct a new ThreadPool object.
   * @param num_threads
   */
  explicit ThreadPool(size_t num_threads) : _threads(num_threads)
  {
    for (size_t i = 0; i < num_threads; ++i) {
      _threads[i] = std::thread([this] {
        while (true) {
          std::unique_lock<std::mutex> lock(_mutex);
          _condition.wait(lock, [this] { return _stop || !_tasks.empty(); });
          if (_stop && _tasks.empty()) { return; }
          auto task = std::move(_tasks.front());
          _tasks.pop();
          lock.unlock();
          task();
        }
      });
    }
  }

  /**
   * @brief Destroy the ThreadPool object.
   */
  ~ThreadPool()
  {
    {
      std::unique_lock<std::mutex> lock(_mutex);
      _stop = true;
    }
    _condition.notify_all();
    for (auto &thread : _threads) { thread.join(); }
  }

  /// @brief Disable copy constructor.
  ThreadPool(const ThreadPool &) = delete;

  /// @brief Disable copy assignment.
  ThreadPool &operator=(const ThreadPool &) = delete;

  /**
   * @brief Add a task to the thread pool.
   * @param task The task to add.
   */
  template<typename F, typename... Args> auto enqueue(F &&f, Args &&...args)
    -> std::future<typename std::result_of<F(Args...)>::type>
  {
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task =
      std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> result = task->get_future();
    {
      std::unique_lock<std::mutex> lock(_mutex);
      if (_stop) { throw std::runtime_error("Thread pool is stopped"); }
      _tasks.emplace([task]() { (*task)(); });
    }
    _condition.notify_one();
    return result;
  }

private:
  /// @brief The stop flag.
  bool _stop{ false };
  /// @brief The mutex.
  std::mutex _mutex;
  /// @brief The threads.
  std::vector<std::thread> _threads;
  /// @brief The condition variable.
  std::condition_variable _condition;
  /// @brief The tasks to execute.
  std::queue<std::function<void()>> _tasks;
};