cmake_minimum_required(VERSION 3.15)

set(This RPG_GAME)
project(${This})

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

add_subdirectory(tests)

set(Headers
        Headers/Backpack.h
        Headers/Box.h
        Headers/Bullet.h
        Headers/Bullet1.h
        Headers/Bullet2.h
        Headers/Bullet3.h
        Headers/Bullet4.h
        Headers/Coin.h
        Headers/CollisionText.h
        Headers/DefaultBullet.h
        Headers/DefaultWeapon.h
        Headers/DiamondWall.h
        Headers/Enemy.h
        Headers/Energy.h
        Headers/Game.h
        Headers/Goblin.h
        Headers/GreenJelly.h
        Headers/Ground1.h
        Headers/Ground2.h
        Headers/Ground3.h
        Headers/GroundWall.h
        Headers/Health.h
        Headers/Item.h
        Headers/Map.h
        Headers/MapObject.h
        Headers/Object.h
        Headers/Player.h
        Headers/Random.h
        Headers/SteelWall.h
        Headers/textDisplay.h
        Headers/Weapon.h
        Headers/Weapon1.h
        Headers/Weapon2.h
        Headers/Weapon3.h
        Headers/Weapon4.h
        Headers/ResourcesContainer.h
        )
set(Sources
        Sources/main.cpp
        Sources/Backpack.cpp
        Sources/Box.cpp
        Sources/Bullet.cpp
        Sources/Bullet1.cpp
        Sources/Bullet2.cpp
        Sources/Bullet3.cpp
        Sources/Bullet4.cpp
        Sources/Coin.cpp
        Sources/CollisionText.cpp
        Sources/DefaultBullet.cpp
        Sources/DefaultWeapon.cpp
        Sources/DiamondWall.cpp
        Sources/Enemy.cpp
        Sources/Energy.cpp
        Sources/Game.cpp
        Sources/Goblin.cpp
        Sources/GreenJelly.cpp
        Sources/Ground1.cpp
        Sources/Ground2.cpp
        Sources/Ground3.cpp
        Sources/GroundWall.cpp
        Sources/Health.cpp
        Sources/Item.cpp
        Sources/Map.cpp
        Sources/MapObject.cpp
        Sources/Object.cpp
        Sources/Player.cpp
        Sources/Random.cpp
        Sources/SteelWall.cpp
        Sources/textDisplay.cpp
        Sources/Weapon.cpp
        Sources/Weapon1.cpp
        Sources/Weapon2.cpp
        Sources/Weapon3.cpp
        Sources/Weapon4.cpp
        Sources/ResourcesContainer.cpp
        )

add_executable(${This} ${Sources} ${Headers})
target_link_libraries (${This} sfml-graphics sfml-window sfml-system)