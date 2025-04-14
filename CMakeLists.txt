cmake_minimum_required(VERSION 3.20)

project(matrix_pg LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(matrix_pg src/main.cpp)

include(GNUInstallDirs)
install(TARGETS matrix_pg
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)