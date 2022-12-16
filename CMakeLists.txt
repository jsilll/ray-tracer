cmake_minimum_required(VERSION 3.16...3.23)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror")

set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

set(ENABLE_DEVELOPER_MODE TRUE CACHE BOOL "Enable 'developer mode'")

project(Raytracer 
        VERSION 0.0.1 
        DESCRIPTION "Raytracer" 
        HOMEPAGE_URL "https://github.com/jsilll/raytracer" 
        LANGUAGES CXX)
        
add_subdirectory(src)