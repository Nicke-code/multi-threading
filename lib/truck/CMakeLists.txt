add_library(LibraryTruck STATIC truck.cpp)
target_include_directories(LibraryTruck PUBLIC "./")
target_link_libraries(LibraryTruck PUBLIC LibraryVehicle)