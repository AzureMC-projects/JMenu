cmake_minimum_required(VERSION 3.21)
project(JMenu VERSION 1.0.0 LANGUAGES CXX)

# Geode's CLI configures the SDK/toolchain and invokes this project.
if (NOT DEFINED ENV{GEODE_SDK} AND NOT DEFINED GEODE_SDK)
    message(STATUS "GEODE_SDK is not set; configure through the Geode CLI.")
endif()

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/core/HackRegistry.cpp
    src/core/SafeMode.cpp
    src/ui/MenuController.cpp
    src/hacks/ExampleHack.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if (DEFINED GEODE_SDK)
    add_subdirectory(${GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
elseif (DEFINED ENV{GEODE_SDK})
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
endif()

setup_geode_mod(${PROJECT_NAME})
