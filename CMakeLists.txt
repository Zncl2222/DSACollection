cmake_minimum_required(VERSION 3.15)
project(DSA)

# Set the source files for your project
set(SOURCES
    LinkList/unittest_LinkList.cpp
)
set(PROJECT_NAME
    DSA
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME}  PRIVATE
    LinkList
)

target_link_libraries(${PROJECT_NAME}  PRIVATE
    gtest
    pthread
)

# Add a custom test target to run the unit tests
add_custom_target(tests
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
)