// Copyright 2022 Zncl2222
#include <gtest/gtest.h>
extern "C" {
#include "binary_tree.h"
}

class BinaryTreeTest : public ::testing::Test {
 protected:
    void SetUp() override {
        // Create a binary tree: 1, 2, 3, 4, -1, 5, 6
        datatype arr[] = {1, 2, 3, 4, -1, 5, 6};
        int size = sizeof(arr) / sizeof(arr[0]);
        root = create_binary_tree(arr, size);
    }

    void TearDown() override {
        free_binary_tree(root);
    }

    struct TreeNode* root;
};

TEST_F(BinaryTreeTest, PreorderTraverse) {
    testing::internal::CaptureStdout();
    preordertraverse(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Value = 1\nValue = 2\nValue = 4\nValue = 3\nValue = 5\nValue = 6\n");
}

TEST_F(BinaryTreeTest, InorderTraverse) {
    testing::internal::CaptureStdout();
    inordertraverse(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Value = 4\nValue = 2\nValue = 1\nValue = 5\nValue = 3\nValue = 6\n");
}

TEST_F(BinaryTreeTest, PostorderTraverse) {
    testing::internal::CaptureStdout();
    postordertraverse(root);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Value = 4\nValue = 2\nValue = 5\nValue = 6\nValue = 3\nValue = 1\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
