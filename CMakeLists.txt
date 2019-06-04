cmake_minimum_required(VERSION 3.14)
project(server)

set(CMAKE_CXX_STANDARD 14)


include_directories(/home/viviana/Descargas/rapidjson-master/include/rapidjson)

add_executable(server main.cpp Logic/GenericLinkedList.h Logic/GenericNode.h Networking/NetPackage.cpp Networking/NetPackage.h Networking/Server.cpp Networking/Server.h)