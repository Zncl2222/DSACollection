#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <malloc.h>

void swap(int* a, int* b){

    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int* array,int front, int end){

    int pivotkey=array[front];

    while(front<end){

        while (front<end && array[end]>=pivotkey){
            end--;
        }
        swap(&array[end],&array[front]);

        while (front<end && array[front]<=pivotkey){
            front++;
        }
        swap(&array[end],&array[front]);

    }

    return front;

}

void quicksort(int* array, int front, int end){

    int pivot;

    if(front<end){

        pivot=Partition(array,front,end);
        quicksort(array,front,pivot-1);
        quicksort(array,pivot+1,end); 
    }
}

int main(){

    int length;
    int random_char=0;
    

    printf("Input the Length of the array\n");
    scanf(" %d",&length);

    printf("Random element? (0=True,1=False)\n");
    scanf(" %f", &random_char);

    int* array=malloc(length*sizeof(int));

    if (random_char==0){
        
        time_t t;
        srand((unsigned) time(&t));

        for (int i=0;i<length;i++){
            array[i]= rand()%5000;
        }

    }
    else{
        printf("Input the element (input the element with a space, ex: 5 6 4 1 2)\n");
        for (int i=0;i<length;i++){
            scanf(" %d",&array[i]);
        }
    }

    printf("Before sorting\n");
    for (int i=0;i<length;i++){
        printf("%d,",array[i]);
    }

    clock_t start_t, end_t;

    start_t=clock();

    quicksort(array,0,length);

    end_t=clock();

    printf("\nAfter sorting\n");
    for (int i=0;i<length;i++){
        printf("%d,",array[i]);
    }

    double totaltime=(double)(end_t-start_t)*1e-3;
    printf("\nTime:%.8fs\n",totaltime);

    printf("\n");
    system("PAUSE");

    return 0;
}