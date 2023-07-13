#include <stdio.h>
#include <stdlib.h>

#include "Link_queue.h"

int main() {
    LinkQueue q;

    LkQueue_Init(&q);

    LkQueue_Pop(&q);
    LkQueue_Getfront(&q);
    LkQueue_Getrear(&q);
    LkQueue_Traverse(&q);
    LkQueue_Size(&q);

    printf("\nLkQueue push\n");
    for (int i = 0; i < 7; i++) {
        LkQueue_Push(&q, i * 2);
        LkQueue_Getfront(&q);
        LkQueue_Getrear(&q);
    }
    LkQueue_Traverse(&q);
    LkQueue_Size(&q);
    LkQueue_Getfront(&q);
    LkQueue_Getrear(&q);

    printf("\nLkQueue pop\n");
    for (int i = 0; i < 4; i++) {
        LkQueue_Pop(&q);
        LkQueue_Traverse(&q);
        LkQueue_Getfront(&q);
        LkQueue_Getrear(&q);
    }
    printf("\nLkQueue push\n");
    for (int i = 0; i < 3; i++) {
        LkQueue_Push(&q, i * 45);
        LkQueue_Traverse(&q);
        LkQueue_Getfront(&q);
        LkQueue_Getrear(&q);
    }

    printf("\nLkQueue pop\n");
    for (int i = 0; i < 6; i++) {
        LkQueue_Pop(&q);
        LkQueue_Traverse(&q);
        LkQueue_Getfront(&q);
        LkQueue_Getrear(&q);
    }

    LkQueue_Pop(&q);
    LkQueue_Traverse(&q);

    LkQueue_Size(&q);

    system("Pause");

    return 0;
}
