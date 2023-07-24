cmake_minimum_required(VERSION 3.25)
project(mips_compiler C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(mips_compiler
        argument.c
        argument.h
        dictionnaire.c
        dictionnaire.h
        mips.c
        parser.c
        parser.h
        writer.c
        writer.h)
