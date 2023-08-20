add_subdirectory(common)
add_subdirectory(interpreter)

add_executable(chip8 main.cpp)

target_include_directories(chip8 PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(chip8 PRIVATE common interpreter)