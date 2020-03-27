cmake_minimum_required(VERSION 3.13)
project(thermalcam)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)
pkg_check_modules(SDL2_ttf REQUIRED IMPORTED_TARGET SDL2_ttf)

include_directories(
        /usr/include
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_ttf_INCLUDE_DIRS}
        3rdparty/mlx90640/include
)

link_directories(
        /usr/lib
        3rdparty/mlx90640/lib
)

# ============================================================================
# ------------------------------ Build camera driver and API -----------------

add_library(mlx90640_api STATIC
        3rdparty/mlx90640/src/MLX90640_API.cpp
        3rdparty/mlx90640/src/MLX90640_LINUX_I2C_Driver.cpp
        3rdparty/mlx90640/include/MLX90640_API.h
        3rdparty/mlx90640/include/MLX90640_I2C_Driver.h)
target_link_libraries(mlx90640_api)
#install(TARGETS mlx90640_api ARCHIVE DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/mlx90640/lib)

# ============================================================================
# ------------------------------ Build application ---------------------------

add_executable(ThermalCamera src/ThermalCamera.cpp src/main.cpp src/constants.h src/colormap.h)
target_link_libraries(ThermalCamera mlx90640_api PkgConfig::SDL2 PkgConfig::SDL2_ttf)
