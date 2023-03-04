add_library(LibraryWarehouse INTERFACE)
target_include_directories(LibraryWarehouse INTERFACE "./")
target_link_libraries(LibraryWarehouse INTERFACE gtest)
target_compile_options(LibraryWarehouse INTERFACE --coverage)