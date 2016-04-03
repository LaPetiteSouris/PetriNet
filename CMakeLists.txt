cmake_minimum_required(VERSION 3.4)
project(PetriNet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp include/Matrice.h include/Marquage.h include/Validation.h src/Marquage.cpp src/Matrice.cpp src/Validation.cpp include/Reseau.h src/Reseau.cpp include/Historique.h src/Historique.cpp)
add_executable(PetriNet ${SOURCE_FILES})