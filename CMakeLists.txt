cmake_minimum_required(VERSION 3.22)

project(
    UDP_CLIENT
    LANGUAGES CXX
    VERSION 0.0.1
)

add_executable(Udp_Client ./dev/src/main.cpp ./dev/src/client.cpp)

target_include_directories(Udp_Client PUBLIC ${CMAKE_SOURCE_DIR}/dev/include)
if(WIN32)
    target_link_libraries(Udp_Client PUBLIC ws2_32)
endif()