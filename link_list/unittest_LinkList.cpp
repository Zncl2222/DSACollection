// Copyright 2022 Zncl2222

#include <gtest/gtest.h>
#include "link_list.h"


class LinkListTest : public ::testing::Test {
 protected:
    struct LinkList* list;

    // SetUp will be called before each test case
    void SetUp() override {
        list = nullptr;
    }

    // TearDown will be called after each test case
    void TearDown() override {
        DeleteLinkList(&list);
    }
};

// Test case for CreateLinkList function
TEST_F(LinkListTest, CreateLinkListTest) {
    CreateLinkList(&list, 5, 0, false);
    EXPECT_EQ(6, Length(&list));
}

// Test case for InsertLinkNode function
TEST_F(LinkListTest, InsertLinkNodeTest) {
    CreateLinkList(&list, 3, 0, false);
    InsertLinkNode(&list, 2, 5);

    EXPECT_EQ(0, Get_ElementValue(&list, 2));
}

// Test case for DeleteLinkNode function
TEST_F(LinkListTest, DeleteLinkNodeTest) {
    CreateLinkList(&list, 3, 0, false);
    DeleteLinkNode(&list, 2);

    EXPECT_EQ(3, Length(&list));
}

// Test case for Get_ElementValue function
TEST_F(LinkListTest, Get_ElementValueTest) {
    CreateLinkList(&list, 3, 0, false);

    EXPECT_EQ(0, Get_ElementValue(&list, 2));
}

// Test case for Get_Elementindex function
TEST_F(LinkListTest, Get_ElementindexTest) {
    CreateLinkList(&list, 3, 5, false);

    EXPECT_EQ(0, Get_Elementindex(&list, 5));
    EXPECT_EQ(-1, Get_Elementindex(&list, 10));
}

// Test case for Length function
TEST_F(LinkListTest, LengthTest) {
    CreateLinkList(&list, 5, 0, false);

    EXPECT_EQ(6, Length(&list));
}

// Test case for Traverse function
TEST_F(LinkListTest, TraverseTest) {
    CreateLinkList(&list, 3, 0, false);

    // Redirect stdout to a string stream for testing
    testing::internal::CaptureStdout();
    Traverse(&list);
    std::string output = testing::internal::GetCapturedStdout();

    // Check the output string
    EXPECT_EQ("DataValue=\n0 0 0 0 \n", output);
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
