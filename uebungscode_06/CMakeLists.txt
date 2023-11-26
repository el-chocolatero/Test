# Konfiguration des Buildsystems CMake
#-------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.14)
# Name des Projekts
project(Zettel06)

# Optionen
#-------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Prüfe ob Heapspeicher gefunden wird,
# der nicht freigegeben wurde
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Füge selbsgeschriebene Includes hinzu
include_directories(include)
# Füge externe Includes hinzu
# include_directories(external)

# Baue Programme
#-------------------------------------------#
add_executable(aufg1 examples/aufg1.cpp src/hilfsfunktionen.cpp src/mergesort.cpp)
add_executable(aufg2 examples/aufg2.cpp src/hilfsfunktionen.cpp src/schnellsort.cpp src/zeitmesser.cpp)
add_executable(aufg3 examples/aufg3.cpp src/simpler_graph.cpp)
