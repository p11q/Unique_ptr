find_package(Catch2 3 REQUIRED PATHS "/home/user/Projects/C++/Unique_ptr/libs" "/home/user/Projects/C++/Unique_ptr")

add_executable(UP_test UP_test.cpp)

target_include_directories(UP_test PUBLIC "/home/user/Projects/C++/Unique_ptr/libs" "/home/user/Projects/C++/Unique_ptr")

target_link_libraries(UP_test PUBLIC Catch2::Catch2WithMain)