cmake_minimum_required(VERSION 3.16...3.23)

# -- Project Setup --

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD_REQUIRED on)

set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

project(Raytracer
        VERSION 0.0.1 
        DESCRIPTION "Raytracer" 
        HOMEPAGE_URL "https://github.com/jsilll/raytracer" 
        LANGUAGES CXX)


# -- Enabling Testing with Catch2

enable_testing()

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

# -- Source --

add_subdirectory(src)