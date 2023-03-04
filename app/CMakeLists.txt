add_executable(main main.cpp)
target_link_options(main PRIVATE --coverage)
target_link_libraries(main PRIVATE LibraryVehicle)
target_link_libraries(main PRIVATE LibraryWarehouse)
target_link_libraries(main PRIVATE LibraryCar)
target_link_libraries(main PRIVATE LibraryTruck)

# Coverage
# In the build folder after a run, type in terminal:
# gcovr -r ../ .