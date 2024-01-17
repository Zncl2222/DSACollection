project(link_list)
set(
    LINK_LIST_TEST_SOURCES
    c/unittest_LinkList.cpp
)
add_executable(unittest_link_list ${LINK_LIST_TEST_SOURCES})
add_library(link_list c/link_list.c)
