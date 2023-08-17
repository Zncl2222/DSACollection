// Copyright 2022 Zncl2222
#include "gtest/gtest.h"
#include "link_stack.h"

// Test fixture for the LinkStack
class LinkStackTest : public testing::Test {
 protected:
    void SetUp() override {
        // Set up any common resources needed for the tests
        link_stack = (LinkStack*)malloc(sizeof(LinkStack));
        link_stack->top = NULL;
        link_stack->count = 0;
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp
        delete_stack(link_stack);
    }

    LinkStack* link_stack;
};

TEST_F(LinkStackTest, CreateStackRandom) {
    create_stack_random(link_stack, 5);
    ASSERT_EQ(stack_length(link_stack), 5);
}

TEST_F(LinkStackTest, StackPop) {
    stack_push(link_stack, 10);
    stack_push(link_stack, 20);
    stack_pop(link_stack);
    ASSERT_EQ(stack_length(link_stack), 1);
    ASSERT_EQ(get_top(link_stack), 10);
}

TEST_F(LinkStackTest, StackLength) {
    stack_push(link_stack, 10);
    stack_push(link_stack, 20);
    ASSERT_EQ(stack_length(link_stack), 2);
}

TEST_F(LinkStackTest, IsEmpty) {
    ASSERT_TRUE(is_empty(link_stack));
    stack_push(link_stack, 10);
    ASSERT_FALSE(is_empty(link_stack));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
