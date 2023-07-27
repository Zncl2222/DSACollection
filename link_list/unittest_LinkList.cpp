// Copyright 2022 Zncl2222

#include <gtest/gtest.h>
#include "link_list.h"


// Test fixture for the LinkList operations
class LinkListTest : public ::testing::Test {
 public:
    void CleanUpLinkList() {
        struct LinkList* temp = (*list)->next;
        while (temp != NULL) {
            struct LinkList* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
        free(*list);
    }
 protected:
    struct LinkList* list;
    void SetUp() override {
        list = nullptr;
    }

    void TearDown() override {
    }
};

// Test case for CreateLinkList function
TEST_F(LinkListTest, CreateLinkListTest) {
    CreateLinkList(&list, 5, 0, false);

    // Check the length of the list
    EXPECT_EQ(6, Length(&list));
}

// Test case for InsertLinkNode function
TEST_F(LinkListTest, InsertLinkNodeTest) {
    CreateLinkList(&list, 3, 0, false);

    InsertLinkNode(&list, 2, 5);

    // Check the value at the target index
    EXPECT_EQ(0, Get_ElementValue(&list, 2));
}

// Test case for DeleteLinkNode function
TEST_F(LinkListTest, DeleteLinkNodeTest) {
    CreateLinkList(&list, 3, 0, false);

    DeleteLinkNode(&list, 2);

    // Check the length of the list after deletion
    EXPECT_EQ(2, Length(&list));
}

// Test case for Get_ElementValue function
TEST_F(LinkListTest, Get_ElementValueTest) {
    CreateLinkList(&list, 3, 0, false);

    // Check the value at the target index
    EXPECT_EQ(0, Get_ElementValue(&list, 2));
}

// Test case for Get_Elementindex function
TEST_F(LinkListTest, Get_ElementindexTest) {
    CreateLinkList(&list, 3, 5, false);

    // Check the index of the target value
    EXPECT_EQ(1, Get_Elementindex(&list, 5));
}

// Test case for Length function
TEST_F(LinkListTest, LengthTest) {
    CreateLinkList(&list, 5, 0, false);

    // Check the length of the list
    EXPECT_EQ(5, Length(&list));
}

// Test case for Traverse function
TEST_F(LinkListTest, TraverseTest) {
    CreateLinkList(&list, 3, 0, false);

    // Redirect stdout to a string stream for testing
    testing::internal::CaptureStdout();
    Traverse(&list);
    std::string output = testing::internal::GetCapturedStdout();

    // Check the output string
    EXPECT_EQ("DataValue=\n0 0\n", output);
}

// Run the tests
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    int res = RUN_ALL_TESTS();
    LinkList::CleanUpLinkList();
    return res;
}
