cmake_minimum_required(VERSION 3.24)


set(CMAKE_CXX_STANDARD 20)

project(SQLite3_Interface)

set(SQLITE_INTERFACE_LIBRARY SQLite_Database)
add_subdirectory(${SQLITE_INTERFACE_LIBRARY})


add_executable(${PROJECT_NAME} main.cpp )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${SQLITE_INTERFACE_LIBRARY})

# Link SQLite3 library
find_package(SQLite3)
include_directories( ${SQLite3_INCLUDE_DIRS})
target_link_libraries (${PROJECT_NAME}  ${SQLite3_LIBRARIES})
