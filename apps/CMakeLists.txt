# -- Raytracer Executable --
add_executable(raytracer main.cpp image.cpp args_parser.cpp)
target_compile_features(raytracer PRIVATE cxx_std_20)
target_link_libraries(raytracer PUBLIC rt)
