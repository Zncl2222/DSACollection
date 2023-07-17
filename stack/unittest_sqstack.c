// Copyright 2022 Zncl2222

#include <stdio.h>
#include <stdlib.h>

#include "Sequential_stack.h"

int main() {
    struct Stack S, S2;

    CreateStack_Random(&S);

    StackTarvarse(&S);

    InitStack(&S2);

    for (int i = 0; i < 5; i++) {
        StackPush(&S2, i);
    }

    StackTarvarse(&S2);

    StackPop(&S2);

    StackTarvarse(&S2);

    system("Pause");

    return 0;
}
