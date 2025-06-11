cmake_minimum_required(VERSION 3.28.3)

project(2dDarkSouls
    VERSION 1.0.0
    LANGUAGES C CXX
)


set(CMAKE_CXX_STANDARD              14)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS           OFF)

set(DS2D_GAME_TARGET_NAME DS2dGame)

add_subdirectory(DS2d)