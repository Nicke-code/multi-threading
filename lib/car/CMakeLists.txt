add_library(LibraryCar STATIC car.cpp)
target_include_directories(LibraryCar PUBLIC "./")
target_link_libraries(LibraryCar PUBLIC LibraryVehicle)