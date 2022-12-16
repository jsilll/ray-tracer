add_library (raylib camera.hpp color.hpp point3.hpp ray.hpp vec3.hpp)
set_target_properties(raylib PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(raylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
