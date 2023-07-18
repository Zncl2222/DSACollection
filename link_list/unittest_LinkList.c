// Copyright 2022 Zncl2222

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "LinkList.h"

int main() {
    struct LinkList *L1;

    CreateLinkList(&L1, 10, 0, true);
    Traverse(&L1);
    InsertLinkNode(&L1, 5, 191);
    Traverse(&L1);
    DeleteLinkNode(&L1, 5);
    Traverse(&L1);

    printf("\nLength = %d\n", Length(&L1));

    system("Pause");
    return 0;
}
