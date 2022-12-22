# -- RT Library --
add_library(rt scene.cpp primitives/sphere.cpp)

# -- Include Directory --
target_include_directories(rt PUBLIC ../include/)

# -- All Warnings as Errors --
if (MSVC)
    target_compile_options(rt PRIVATE /WX)
else ()
    target_compile_options(rt PRIVATE -Werror)
endif ()

# -- Release and Debug Flags --
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(rt PRIVATE -O3 -march=native -mtune=native -fopenmp)
elseif (CMAKE_BUILD_TYPE STREQUAL "ReleaseCrossPlatform")
    target_compile_options(raytracer PRIVATE -O3 -march=x86-64 -mtune=x86-64 -fopenmp)
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(rt PRIVATE -g -O0)
endif ()
