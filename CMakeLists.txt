cmake_minimum_required(VERSION 4.2)
project(CRogueLite)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror)


# 1. Locate the vcpkg-installed SFML package (Note the exact casing)
find_package(SFML COMPONENTS Graphics Window System CONFIG REQUIRED)

# 2. Match this to your actual executable name and source file
add_executable(CRogueLite MainMenuState.cpp
        main.cpp
        helpers/Logger.h
        helpers/GameEngine.h
        helpers/GameState.h
        GameEngine.cpp
        helpers/MainMenuState.h
)
# 3. Explicitly map the SFML targets to your executable
target_link_libraries(CRogueLite PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)

# 4. Copy assets to the build directory after each build
add_custom_command(TARGET CRogueLite POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:CRogueLite>/assets
)
