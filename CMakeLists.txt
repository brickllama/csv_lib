cmake_minimum_required(VERSION 4.0)
project(csv_lib C)

set(CMAKE_C_STANDARD 11)

set(SOURCES
        src/csv_reader.c
        src/csv_writer.c
        src/var.c
)

add_library(csv_lib SHARED ${SOURCES})

target_include_directories(csv_lib PUBLIC ${PROJECT_SOURCE_DIR}}/include)
