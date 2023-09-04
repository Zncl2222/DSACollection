// Copyright 2022 Zncl2222
#include <gtest/gtest.h>
extern "C" {
#include "sequential_queue.h"
}

TEST(SqQueueTest, Initialization) {
    SqQueue q;
    SqQueue_Init(&q);
    ASSERT_EQ(SqQueue_Length(&q), 0);
}

TEST(SqQueueTest, PushAndPop) {
    SqQueue q;
    SqQueue_Init(&q);

    SqQueue_Push(&q, 42);
    ASSERT_EQ(SqQueue_Length(&q), 1);

    SqQueue_Push(&q, 10);
    SqQueue_Push(&q, 20);
    ASSERT_EQ(SqQueue_Length(&q), 3);

    SqQueue_Pop(&q);
    ASSERT_EQ(SqQueue_Length(&q), 2);

    SqQueue_Pop(&q);
    SqQueue_Pop(&q);
    ASSERT_EQ(SqQueue_Length(&q), 0);
}

TEST(SqQueueTest, GetFrontAndRear) {
    SqQueue q;
    SqQueue_Init(&q);

    SqQueue_Push(&q, 5);
    SqQueue_Push(&q, 10);

    ASSERT_EQ(SqQueue_Getfront(&q), 5);
    ASSERT_EQ(SqQueue_Getrear(&q), 10);

    SqQueue_Pop(&q);

    ASSERT_EQ(SqQueue_Getfront(&q), 10);
    ASSERT_EQ(SqQueue_Getrear(&q), 10);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
