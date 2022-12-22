# -- Catch2 --
enable_testing()
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)

# -- Finding all files that match test_*.cpp --
file(GLOB TESTS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/primitives/test_*.cpp)

# -- Adding tests --
foreach (TEST_SRC ${TESTS_SRC})
    # -- Extracting Filename --
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WLE)

    # -- Adding Executable --
    add_executable(${TEST_NAME} ${TEST_SRC})

    # -- Adding Test --
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

    # -- Linking Libraries --
    target_link_libraries(${TEST_NAME} PRIVATE rt Catch2::Catch2WithMain)

    # -- All Warnings as Errors --
    if (MSVC)
        target_compile_options(${TEST_NAME} PRIVATE /WX)
    else ()
        target_compile_options(${TEST_NAME} PRIVATE -Werror)
    endif ()

    # -- Release and Debug --
    if (CMAKE_BUILD_TYPE MATCHES Release)
        target_compile_options(${TEST_NAME} PRIVATE -O3 --coverage)
    elseif (CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_options(${TEST_NAME} PRIVATE -g -O0)
    endif ()
endforeach ()