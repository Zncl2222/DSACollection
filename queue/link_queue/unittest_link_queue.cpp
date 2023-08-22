// Copyright 2022 Zncl2222
#include <gtest/gtest.h>
#include "link_queue.h"

class LinkQueueTest : public ::testing::Test {
 protected:
    void SetUp() override {
        lk_queue_init(&queue);
    }

    void TearDown() override {
        lk_queue_destroy(&queue);
    }

    LinkQueue queue;
};

TEST_F(LinkQueueTest, PushAndPop) {
    lk_queue_push(&queue, 42);
    lk_queue_pop(&queue);
    EXPECT_EQ(lk_queue_size(&queue), 0);
}

TEST_F(LinkQueueTest, GetFrontAndRear) {
    lk_queue_push(&queue, 10);
    lk_queue_push(&queue, 20);
    lk_queue_push(&queue, 30);

    EXPECT_EQ(lk_queue_get_front(&queue), 10);
    EXPECT_EQ(lk_queue_get_rear(&queue), 30);
}

TEST_F(LinkQueueTest, Size) {
    lk_queue_push(&queue, 5);
    lk_queue_push(&queue, 15);
    lk_queue_push(&queue, 25);

    EXPECT_EQ(lk_queue_size(&queue), 3);
}

TEST_F(LinkQueueTest, Traverse) {
    testing::internal::CaptureStdout();
    lk_queue_push(&queue, 7);
    lk_queue_push(&queue, 14);
    lk_queue_push(&queue, 21);
    lk_queue_traverse(&queue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "\nLkQueue :\n7 14 21 \n\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
