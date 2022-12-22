# -- Setting up Doxygen --
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

# -- RT Public Headers --
file(GLOB LIB_RT_FILES ../include/rt/*.hpp ../include/rt/primitives/*.hpp)

# -- Building Documentation --
doxygen_add_docs(docs ${LIB_RT_FILES})