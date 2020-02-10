cmake_minimum_required(VERSION 3.4)

set(This RPG_GAME)
project(${This})

option(BUILD_TESTS Off)
option(BUILD_COVERAGE "Build coverage" ON)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "SFML-2.5.1/lib")
set(SFML_DIR "SFML-2.5.1/lib/cmake/SFML")
link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
find_package(SFML 2.5.1 COMPONENTS system window graphics)

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


add_executable(${This} Sources/main.cpp ${Sources} ${Headers})
target_link_libraries (${This} sfml-graphics sfml-window sfml-system)

# Tests
if (BUILD_TESTS)

enable_testing()

add_subdirectory(Packages/googletest)
include_directories(Packages/googletest/googletest/include)

add_executable(tests
        tests/tests.cpp
        ${Sources}
        ${Headers}
        )

target_link_libraries(tests gtest gtest_main sfml-graphics
        sfml-window sfml-system)

add_test(NAME tests COMMAND tests)

endif()

if (BUILD_COVERAGE)
    set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
    find_package(codecov)
    add_coverage(tests)
    list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
    coverage_evaluate()
endif ()