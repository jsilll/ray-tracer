add_library (
        rt
        camera.hpp
        color.hpp
        point.hpp
        ray.hpp
        vec3.hpp)
set_target_properties(rt PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(rt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
