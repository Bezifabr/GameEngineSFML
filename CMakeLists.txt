cmake_minimum_required (VERSION 2.8.12)

# add c++11 standard to compiler
add_compile_options(-std=c++11)

project(GESFML)


file(GLOB_RECURSE SRC_FILES
    GLOB_CPP_PATTERNS src/*.cpp */GESFML/*.cpp
    GLOB_H_PATTERNS include/*.h */GESFML/*.h RECURSE_GROUP
)

set(EXE_NAME "GESFML")
add_executable(${EXE_NAME} ${SRC_FILES})

set(GESFML_INCLUDE_DIR & ${CMAKE_CURRENT_SOURCE_DIR}/include/GESFML)

include_directories(${GESFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SFML_DIR}/include)


if(WIN32 OR MINGW OR MSVC)
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/sfml")

# link with SFML library dependiences
target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(${EXE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml/include"
)
endif(WIN32 OR MINGW OR MSVC)



if(UNIX)

#SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
endif()

endif(UNIX)
