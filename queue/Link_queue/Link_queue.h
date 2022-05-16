# include <stdio.h>

typedef int datatype;

typedef struct Queue_Node{

    datatype data;
    struct Queue_Node* next;

}QNode, *QueuePtr;

typedef struct{
    QueuePtr front, rear;
}LinkQueue;

void LkQueue_Init(LinkQueue* q){

    printf("LkQueue init success\n");
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    q->front->next = NULL;
}

void LkQueue_Push(LinkQueue* q, datatype val){

    QueuePtr next_node = (QueuePtr)malloc(sizeof(QNode));

    if(!next_node)
        return;

    next_node->data = val;
    next_node->next = NULL;

    q->rear->next = next_node;
    q->rear = next_node;
}

void LkQueue_Pop(LinkQueue* q){

    QueuePtr temp;

    if(q->front == q->rear){
        printf("(LkQueue_Pop) ERROR: Queue is empty\n");
        return;
    }

    temp = q->front->next;

    q->front->next = temp->next;
    
    if(q->rear == temp)
        q->rear = q->front;

    free(temp);
}

datatype LkQueue_Getfront(LinkQueue* q){

    if(q->front == q->rear){
        printf("(LkQueue_Getfront) ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(LkQueue_Getfront) Front ptr value %d\n", q->front->next->data);
    return q->front->next->data;
}

datatype LkQueue_Getrear(LinkQueue* q){

    if(q->front == q->rear){
        printf("(LkQueue_Getrear) ERROR: Queue is empty\n");
        return -9999;
    }
    printf("(LkQueue_Getrear) Rear ptr value %d\n", q->rear->data);
    return q->rear->data;
}

int LkQueue_Size(LinkQueue* q){

    QueuePtr temp = q->front;
    int count = 0;

    while (q->rear != temp){
        temp = temp->next;
        count++;
    }
    printf("(LkQueue_Size) Queue size = %d\n",count);
    return count;
}

void LkQueue_Traverse(LinkQueue* q){

    if(q->rear == q->front){
        printf("(LkQueue_Traverse) ERROR: Queue is empty\n");
        return;
    }
    QueuePtr temp;
    temp = q->front->next;
    printf("\nLkQueue :\n");
    while(temp){

        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}