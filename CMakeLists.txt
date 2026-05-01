cmake_minimum_required(VERSION 4.2)
project(rotmg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rotmg main.cpp
        Player.cpp
        Player.hpp
        Animation.cpp
        Animation.hpp
        UI.cpp
        UI.hpp
        Tilemap.cpp
        Tilemap.hpp
        Inventory.cpp
        Inventory.hpp
        TextureDeclarations.cpp
        TextureDeclarations.hpp
        Bullets.cpp
        Bullets.hpp
        TestEntity.cpp
        TestEntity.hpp
        Enemies.cpp
        Enemies.hpp
        PlayerProjectiles.cpp
        PlayerProjectiles.hpp
)

target_include_directories(rotmg PRIVATE /usr/local/include)
target_link_directories(rotmg PRIVATE /usr/local/lib)
target_link_libraries(rotmg PRIVATE
        raylib
        "-framework OpenGL"
        "-framework Cocoa"
        "-framework IOKit"
)

