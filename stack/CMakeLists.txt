project(link_stack)
set(
    LINK_STACK_TEST_SOURCES
    c/unittest_link_stack.cpp
)
add_executable(unittest_link_stack ${LINK_STACK_TEST_SOURCES})
add_library(link_stack c/link_stack.c)

project(sq_stack)
set(
    SQ_STACK_TEST_SOURCES
    c/unittest_sq_stack.cpp
)
add_executable(unittest_sq_stack ${SQ_STACK_TEST_SOURCES})
add_library(sq_stack c/sequential_stack.c)
