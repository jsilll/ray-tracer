cmake_minimum_required(VERSION 3.21)

# -- Setup --
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT ON)

# -- Project Metadata --
project(Raytracer
        VERSION 0.0.1
        DESCRIPTION "Raytracer"
        HOMEPAGE_URL "https://github.com/jsilll/raytracer"
        LANGUAGES CXX)

# -- Baseline Flags --
if (MSVC)
    add_compile_options(/W4 /w14640)
else()
    add_compile_options(
            -Wall -Wextra -Wshadow -Wunused -Wnon-virtual-dtor -pedantic)
endif()

# -- When Building Standalone --
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # -- Testing Only Available When Building Standalone --
    include(CTest)
    enable_testing()

    # -- Ensure that the -std=c++xx flag is used --
    set(CMAKE_CXX_EXTENSIONS OFF)

    # -- Support for folders in IDEs --
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # -- Docs only available when building Standalone --
    find_package(Doxygen)
    if (Doxygen_FOUND)
        add_subdirectory(docs)
    else ()
        message(STATUS "Doxygen not found, not able to build docs")
    endif ()
endif ()

# -- Library --
add_subdirectory(src)

# -- Executable --
add_subdirectory(apps)

# -- Testing only available when building Standalone --
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
endif ()