cmake_minimum_required(VERSION 3.7.2)

set(PROJECT_NAME vector_list)
set(TARGET_NAME vl)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/main
    ${CMAKE_SOURCE_DIR}/list
    ${CMAKE_SOURCE_DIR}/vector
)

add_executable(${TARGET_NAME}
    ${CMAKE_SOURCE_DIR}/main/main.cpp
    ${CMAKE_SOURCE_DIR}/list/list.cpp
    ${CMAKE_SOURCE_DIR}/vector/vector.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDE_DIRECTORIES})

target_compile_options(${TARGET_NAME} PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
        )