# -- RT Library --
add_library(rt scene.cpp primitives/sphere.cpp materials/lambertian_alt.cpp materials/lambertian_hack.cpp materials/lambertian_true.cpp materials/metal.cpp)

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
    target_compile_options(rt PRIVATE -O3 -march=native)
elseif (CMAKE_BUILD_TYPE MATCHES ReleaseCrossPlatform)
    target_compile_options(raytracer PRIVATE -O3 -march=x86-64)
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(rt PRIVATE -g -O0)
    target_compile_definitions(rt PRIVATE DEBUG)
endif ()
