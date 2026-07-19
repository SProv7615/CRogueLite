cmake_minimum_required(VERSION 4.2)
project(CRogueLite)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)


# 1. Locate the vcpkg-installed SFML package (Note the exact casing)
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)

# 2. Match this to your actual executable name and source file
add_executable(CRogueLite default_main.cpp
        main.cpp
)
# 3. Explicitly map the SFML targets to your executable
target_link_libraries(CRogueLite PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
