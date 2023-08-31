// Copyright 2022 Zncl2222

#include <gtest/gtest.h>
extern "C" {
#include "link_list.h"
}


class LinkListTest : public ::testing::Test {
 protected:
    struct LinkList* list;

    // SetUp will be called before each test case
    void SetUp() override {
        list = nullptr;
    }

    // TearDown will be called after each test case
    void TearDown() override {
        delete_link_list(&list);
    }
};

// Test case for create_link_list function
TEST_F(LinkListTest, create_link_list_test) {
    create_link_list(&list, 5, 0, false);
    EXPECT_EQ(6, link_list_length(&list));
}

// Test case for insert_link_node function
TEST_F(LinkListTest, insert_link_node_test) {
    create_link_list(&list, 3, 0, false);
    insert_link_node(&list, 2, 5);

    EXPECT_EQ(0, get_element_val(&list, 2));
}

// Test case for delete_link_node function
TEST_F(LinkListTest, delete_link_node_test) {
    create_link_list(&list, 3, 0, false);
    delete_link_node(&list, 2);

    EXPECT_EQ(3, link_list_length(&list));
}

// Test case for get_element_val function
TEST_F(LinkListTest, get_element_val_test) {
    create_link_list(&list, 3, 0, false);

    EXPECT_EQ(0, get_element_val(&list, 2));
}

// Test case for get_element_idx function
TEST_F(LinkListTest, get_element_idx_test) {
    create_link_list(&list, 3, 5, false);

    EXPECT_EQ(0, get_element_idx(&list, 5));
    EXPECT_EQ(-1, get_element_idx(&list, 10));
}

// Test case for link_list_length function
TEST_F(LinkListTest, link_list_length_test) {
    create_link_list(&list, 5, 0, false);

    EXPECT_EQ(6, link_list_length(&list));
}

// Test case for Traverse function
TEST_F(LinkListTest, traverse_test) {
    create_link_list(&list, 3, 0, false);

    // Redirect stdout to a string stream for testing
    testing::internal::CaptureStdout();
    traverse(&list);
    std::string output = testing::internal::GetCapturedStdout();

    // Check the output string
    EXPECT_EQ("DataValue=\n0 0 0 0 \n", output);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
