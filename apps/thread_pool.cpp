#include <thread_pool.hpp>

ThreadPool::ThreadPool(size_t num_threads) noexcept : _threads(num_threads)
{
  for (std::size_t i = 0; i < num_threads; ++i) {
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

ThreadPool::~ThreadPool() noexcept
{
  {
    std::unique_lock<std::mutex> lock(_mutex);
    _stop = true;
  }
  _condition.notify_all();
  for (auto &thread : _threads) { thread.join(); }
}
