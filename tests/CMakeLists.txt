file(GLOB TESTS_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test_*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/primitives/test_*.cpp)

foreach (TEST_SRC ${TESTS_SRC})
    get_filename_component(TEST_NAME ${TEST_SRC} NAME_WLE)
    add_executable(${TEST_NAME} ${TEST_SRC})
    target_link_libraries(${TEST_NAME} PUBLIC rt PRIVATE Catch2::Catch2WithMain)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

    if (MSVC)
        target_compile_options(${TEST_NAME} PUBLIC /Wall /WX)
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
        target_compile_options(${TEST_NAME} PUBLIC -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
                -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
                -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
    endif ()

    if (CMAKE_CXX_COMPILE_ID MATCHES "GNU")
        target_compile_option(${TEST_NAME} PUBLIC -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
    endif ()

    if (CMAKE_BUILD_TYPE MATCHES Debug)
        target_compile_options(${TEST_NAME} PUBLIC -g -O0)
    elseif (CMAKE_BUILD_TYPE MATCHES Release)
        target_compile_options(${TEST_NAME} PUBLIC -O3 -march=native)
    endif ()

endforeach ()