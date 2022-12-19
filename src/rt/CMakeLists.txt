# -- Library --

add_library(rt
        camera.h color.h point.h ray.h vec3.h
        primitives/sphere.h primitives/surface.h primitives/sphere.cpp)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

target_include_directories(rt PUBLIC ${PARENT_DIR})

set_target_properties(rt PROPERTIES LINKER_LANGUAGE CXX)

# -- Compiler Flags --

if (MSVC)
    target_compile_options(rt PUBLIC /W4 /w14640 /permissive)
else ()
    target_compile_options(rt PUBLIC -pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
            -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
            -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(rt PUBLIC -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(rt PUBLIC -g -O0)
elseif (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(rt PUBLIC -O3 -march=native)
endif ()
