# -- Documentation --
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
file(GLOB LIB_RT_FILES ../include/rt/*.hpp ../include/rt/primitives/*.hpp)
doxygen_add_docs(docs ${LIB_RT_FILES})