cmake_minimum_required(VERSION 2.8)
project(tsa_protoc)

#set(CMAKE_CXX_FLAGS "-std=c++1z -g -Wall `pkg-config --cflags --libs protobuf`")
set(CMAKE_CXX_FLAGS "-std=c++11 -g -Wall")

include_directories(cpp_out)
# get google protobuf
get_filename_component(PROTOBUF "/home/roy/usr/protobuf" ABSOLUTE)
include_directories(${PROTOBUF}/include)
link_directories(${PROTOBUF}/lib)

add_executable(add_person src/add_person.cc cpp_out/addressbook.pb.cc)
target_link_libraries(add_person protobuf)
add_executable(list_people src/list_people.cc cpp_out/addressbook.pb.cc)
target_link_libraries(list_people protobuf)
