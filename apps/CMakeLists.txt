# -- Raytracer Executable --
add_executable(raytracer main.cpp image.cpp clap.cpp logger.cpp scenes.cpp)

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
if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_options(raytracer PRIVATE -O3 -march=native)
elseif (CMAKE_BUILD_TYPE MATCHES ReleaseCrossPlatform)
    target_compile_options(raytracer PRIVATE -O3 -march=x86-64)
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_options(raytracer PRIVATE -g -O0)
    target_compile_definitions(raytracer PRIVATE DEBUG)
endif ()
