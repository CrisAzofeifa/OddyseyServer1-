cmake_minimum_required(VERSION 3.9)
project(Main)

set(CMAKE_CXX_STANDARD 11)

add_executable(Main base64.cpp base64.h Chunk.cpp Chunk.h Oddysey_server.cpp Oddysey_server.h pugixml.cpp DataBase/Metadata.cpp DataBase/Query.cpp DataBase/Metadata.h DataBase/Query.h DataBase/Userdata.cpp DataBase/Userdata.cpp List.h ListNode.h )