# -- RT Library --
add_library(rt scene.cpp primitives/sphere.cpp)
target_compile_features(rt PUBLIC cxx_std_20)
target_include_directories(rt PUBLIC ../include/)
set_target_properties(rt PROPERTIES LINKER_LANGUAGE CXX)
