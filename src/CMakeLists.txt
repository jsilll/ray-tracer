add_subdirectory(raylib)

add_executable(raytracer main.cpp)

target_link_libraries(raytracer LINK_PUBLIC raylib)
