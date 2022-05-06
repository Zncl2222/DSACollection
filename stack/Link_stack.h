# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <stdbool.h>

typedef int datatype;

typedef struct StackNode{

    datatype val;
    struct StackNode* next;

}StackNode, *LinkStack_ptr;

typedef struct{

    LinkStack_ptr top;
    int count;

}LinkStack;

void CreateStack_Random(LinkStack *S, int L_size){

    S->count=0;

    for(int i=0; i<L_size; i++){

        LinkStack_ptr s=(LinkStack_ptr)malloc(sizeof(StackNode));
        s->val=rand()%100+1;
        s->next=S->top;
        S->top=s;
        S->count++;
    }

}

bool IsEmpty(LinkStack *S){

    if(S->top==NULL)
        return true;
    else
        return false;

}

datatype GetTop(LinkStack *S){

    return (datatype)S->top;
}

void StackPush(LinkStack *S, datatype value){

    LinkStack_ptr s=(LinkStack_ptr)malloc(sizeof(StackNode));
    s->val=value;
    s->next=S->top;
    S->top=s;
    S->count++;

}

void StackPop(LinkStack *S){

    LinkStack_ptr temp=(LinkStack_ptr)malloc(sizeof(StackNode));

    if(IsEmpty(S))
        exit(0);

    temp=S->top;
    S->top=S->top->next;
    free(temp);
    S->count--;

}

int StackLength(LinkStack *S){

    return S->count;
}

void StackTarvarse(LinkStack *S){

    LinkStack_ptr temp=(LinkStack_ptr)malloc(sizeof(StackNode));
    datatype* temp_array=(datatype*)malloc(S->count*sizeof(datatype));

    temp=S->top;
    
    for(int i=0; i<S->count; i++){
        temp_array[S->count-i-1]=temp->val;
        temp=temp->next;
    }

    for(int i=0; i<S->count; i++){
        printf("%d ",temp_array[i]);
    }

    free(temp_array);
    
    printf("\nStack number = %d\n",S->count);
}