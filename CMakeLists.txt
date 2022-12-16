cmake_minimum_required(VERSION 3.16...3.23)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wpedantic -Werror)
endif()

set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

project(Raytracer
        VERSION 0.0.1 
        DESCRIPTION "Raytracer" 
        HOMEPAGE_URL "https://github.com/jsilll/raytracer" 
        LANGUAGES CXX)
        
add_subdirectory(src)