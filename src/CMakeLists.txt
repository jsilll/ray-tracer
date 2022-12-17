# -- Adding Library --

add_subdirectory(rt)

# -- Executable --

add_executable(raytracer main.cpp)

target_link_libraries(raytracer LINK_PUBLIC rt)
