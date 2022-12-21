# -- Executable --

add_executable(raytracer main.cpp image.cpp args_parser.cpp)

target_link_libraries(raytracer PUBLIC rt)

# -- Compiler Flags --

if (MSVC)
    target_compile_options(raytracer PUBLIC /Wall /WX)
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(raytracer PUBLIC -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
            -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
            -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
endif ()

if (CMAKE_CXX_COMPILE_ID MATCHES "GNU")
    target_compile_option(raytracer PUBLIC -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(raytracer PUBLIC -g -O0)
    target_compile_definitions(raytracer PUBLIC DEBUG)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(raytracer PUBLIC -O3 -march=native)
endif ()
