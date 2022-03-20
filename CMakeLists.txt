cmake_minimum_required(VERSION 3.21)
project(new C)

set(CMAKE_C_STANDARD 99)

add_executable(new main.c book_management.c book_management.h page.c page.h user.c user.h librarian.c librarian.h login.c login.h)
