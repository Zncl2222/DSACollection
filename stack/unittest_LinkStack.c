// Copyright 2022 Zncl2222

#include <stdio.h>
#include <stdlib.h>

#include "Link_stack.h"

int main() {
    LinkStack S;

    CreateStack_Random(&S, 5);

    StackTarvarse(&S);

    for (int i = 0; i < 5; i++) {
        StackPush(&S, i * i);
    }

    StackTarvarse(&S);

    StackPop(&S);

    StackTarvarse(&S);

    system("Pause");

    return 0;
}
