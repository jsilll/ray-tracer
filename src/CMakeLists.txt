# -- Library --

add_library(rt
        scene.cpp
        primitives/sphere.cpp)

target_include_directories(rt PUBLIC ${CMAKE_SOURCE_DIR}/include/)

set_target_properties(rt PROPERTIES LINKER_LANGUAGE CXX)

# -- Compiler Flags --

if (MSVC)
    target_compile_options(rt PUBLIC /Wall /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(rt PUBLIC -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
            -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
            -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
endif ()

if (CMAKE_CXX_COMPILE_ID MATCHES "GNU")
    target_compile_option(rt PUBLIC -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(rt PUBLIC -g -O0)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(rt PUBLIC -O3 -march=native)
endif ()