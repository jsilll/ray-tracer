# -- Adding Library --

add_subdirectory(rt)

# -- Adding Library Tests --

add_subdirectory(tests)

# -- Executable --

add_executable(raytracer main.cpp)

target_link_libraries(raytracer PUBLIC rt)

# -- Compiler Flags --

if (MSVC)
    target_compile_options(raytracer PUBLIC /W4 /w14640 /permissive)
else ()
    target_compile_options(raytracer PUBLIC -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
            -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
            -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(raytracer PUBLIC -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(raytracer PUBLIC -g -O0)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(raytracer PUBLIC -O3 -march=native)
endif ()
