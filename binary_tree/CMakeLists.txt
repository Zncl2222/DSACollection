project(binary_tree)
set(
    BINARY_TREE_TEST_SOURCES
    c/unittest_binary_tree.cpp
)
add_executable(unittest_binary_tree ${BINARY_TREE_TEST_SOURCES})
add_library(binary_tree c/binary_tree.c)
