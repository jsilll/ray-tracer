# -- Compiler Flags --

if (MSVC)
    add_compile_options(/W4 /w14640 /permissive)
else()
    add_compile_options(-pedantic -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align
            -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation
            -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast
            -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Werror)
endif()

# -- Library --

add_library (
        rt
        camera.hpp
        color.hpp
        point.hpp
        ray.hpp
        vec3.hpp)
set_target_properties(rt PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(rt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# -- Tests --

add_subdirectory(tests)