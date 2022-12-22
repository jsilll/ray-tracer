# -- Catch2 --
enable_testing()
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# -- Finding all files that match test_*.cpp --
file(GLOB TESTS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/primitives/test_*.cpp)

# -- Adding tests --
foreach (TEST_SRC ${TESTS_SRC})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WLE)
    add_executable(${TEST_NAME} ${TEST_SRC})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    target_compile_features(${TEST_NAME} PRIVATE cxx_std_20)
    target_link_libraries(${TEST_NAME} PRIVATE rt Catch2::Catch2WithMain)
endforeach ()