add_library(interpreter cpu.cpp)

target_include_directories(interpreter PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(interpreter PRIVATE common)