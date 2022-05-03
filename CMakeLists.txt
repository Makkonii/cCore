cmake_minimum_required(VERSION 3.22)
project(cCore C)

set(CMAKE_C_STANDARD 99)

find_library(gmp gmp)

add_executable(cCore main.c constants/opcodes.h src/login/loginServer.c src/login/loginServer.h src/utils/bufferReader.h src/utils/bufferReader.c src/login/loginOpCodeHandler.c src/login/loginOpCodeHandler.h src/login/loginStructs.h src/srp/srp6.c src/srp/srp6.h)
target_link_libraries(cCore gmp)
