# -- Raytracer Executable --
add_executable(raytracer main.cpp image.cpp clap.cpp)

# -- Linking Libraries --
target_link_libraries(raytracer PRIVATE rt)

# -- Include Directories --
target_include_directories(raytracer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# -- All Warnings as Errors --
if (MSVC)
    target_compile_options(raytracer PRIVATE /WX)
else ()
    target_compile_options(raytracer PRIVATE -Werror)
endif ()

# -- Release and Debug Flags --
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(raytracer PRIVATE -O3 -march=native -mtune=native -fopenmp)
elseif (CMAKE_BUILD_TYPE STREQUAL "ReleaseCrossPlatform")
    target_compile_options(raytracer PRIVATE -O3 -march=x86-64 -mtune=x86-64 -fopenmp)
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(raytracer PRIVATE -g -O0)
    target_compile_definitions(raytracer PRIVATE DEBUG)
endif ()
