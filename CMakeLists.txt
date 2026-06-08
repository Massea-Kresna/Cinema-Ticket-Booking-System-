cmake_minimum_required(VERSION 3.10)
project(CinemaBookingSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Menambahkan library pthread untuk multithreading di Linux/Mac (opsional di Windows)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(CinemaBookingSystem ${SOURCES})
target_link_libraries(CinemaBookingSystem Threads::Threads)