#CMakeLists.txt proposed by school
# cmake_minimum_required(VERSION 3.5)
# project(TP1)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# include_directories(.)

# add_executable(TP1
#         Case.cpp
#         Case.h
#         File.h
#         File.hpp
#         GenerateurAleatoireJeuSerpentsEtEchelles.cpp
#         GenerateurAleatoireJeuSerpentsEtEchelles.h
#         GenerateurNombresAleatoires.cpp
#         GenerateurNombresAleatoires.h
#         JeuSerpentsEtEchelles.cpp
#         JeuSerpentsEtEchelles.h
#         ListeCirculaire.h
#         ListeCirculaire.hpp
#         ListeDeCases.cpp
#         ListeDeCases.h
#         Principal.cpp)

#CMakeLists.txt for VSCODE My local mingw
#cmake_minimum_required(VERSION 3.20)
#
#project(TP1)
#
#set(CMAKE_CXX_STANDARD 14)
#
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wfatal-errors")
#
#set(GTEST_INCLUDE_PATH "D:/googletest/googletest/include/")
#
#include_directories(${GTEST_INCLUDE_PATH})
#
#set(GTEST_LIBRARY_PATH "D:/googletest/build/lib/libgtest.a")
#
#set(GTEST_MAIN_LIBRARY_PATH "D:/googletest/build/lib/libgtest_main.a")
#
#file(GLOB SRC_FILES ./*.cpp)
#
#add_executable(${PROJECT_NAME} ${SRC_FILES})
#
#target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARY_PATH} ${GTEST_MAIN_LIBRARY_PATH} pthread)

#CMakeLists.txt for CLion IDE
cmake_minimum_required(VERSION 3.20)

project(TP1)

set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG  v1.12.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB SRC_FILES ./*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

enable_testing()

target_link_libraries(${PROJECT_NAME} gtest_main gtest pthread)

include(GoogleTest)
