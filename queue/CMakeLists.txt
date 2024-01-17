project(link_queue)
set(
    LINK_QUEUE_TEST_SOURCES
    c/unittest_link_queue.cpp
)
add_executable(unittest_link_queue ${LINK_QUEUE_TEST_SOURCES})
add_library(link_queue c/link_queue.c)

project(sq_queue)
set(
    SQ_QUEUE_TEST_SOURCES
    c/unittest_sequential_queue.cpp
)
add_executable(unittest_sq_queue ${SQ_QUEUE_TEST_SOURCES})
add_library(sq_queue c/sequential_queue.c)
