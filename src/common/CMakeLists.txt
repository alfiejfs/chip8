add_library(common types.cpp)

target_include_directories(common PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
