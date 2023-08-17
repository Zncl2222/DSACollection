// Copyright 2022 Zncl2222
#include "gtest/gtest.h"
#include "sequential_stack.h"

class SequentialStackTest : public testing::Test {
 protected:
    void SetUp() override {
        init_stack(&stack);
    }

    struct Stack stack;
};

TEST_F(SequentialStackTest, PushAndPop) {
    stack_push(&stack, 10);
    ASSERT_EQ(get_top(&stack), 0);
    ASSERT_EQ(stack_length(&stack), 0);

    stack_push(&stack, 20);
    ASSERT_EQ(get_top(&stack), 1);
    ASSERT_EQ(stack_length(&stack), 1);

    stack_pop(&stack);
    ASSERT_EQ(get_top(&stack), 0);
    ASSERT_EQ(stack_length(&stack), 0);
}

TEST_F(SequentialStackTest, IsEmpty) {
    ASSERT_TRUE(is_empty(&stack));

    stack_push(&stack, 10);
    ASSERT_FALSE(is_empty(&stack));
}

TEST_F(SequentialStackTest, StackTraverse) {
    testing::internal::CaptureStdout();

    stack_push(&stack, 10);
    stack_push(&stack, 20);
    stack_push(&stack, 30);

    stack_traverse(&stack);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "10 20 \nThe idx of top is : 2\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
