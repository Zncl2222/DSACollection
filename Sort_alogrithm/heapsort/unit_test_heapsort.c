# include <stdio.h>
# include "heapsort.h"

int unit_test(int* L, int L_size){

    printf("Before\n");
    PrintArray(L,L_size);

    HeapSort(L,L_size);

    printf("After\n");
    PrintArray(L,L_size);
}

int main(){

    // Test case

    int L1[]={9,6,8,1,2,4};         // answer 1 2 4 6 8 9
    int L2[]={6,6,6,1,2,5,1,2,1,-5};// answer -5 1 1 1 2 2 5 6 6 6
    int L3[]={9};                   // answer 9
    int L4[]={};                    // answer NULL

    int L1_size=6;
    int L2_size=10;
    int L3_size=1;
    int L4_size=0;

    printf("Unit test (heap sort)");
    ///##################################################

    printf("\n\n##########Case1##########\n\n");
    unit_test(L1,L1_size);
    printf("Expected answer \n1 2 4 6 8 9");

    //##################################################

    printf("\n\n##########Case2##########\n\n");
    unit_test(L2,L2_size);
    printf("Expected answer \n-5 1 1 1 2 2 5 6 6 6");

    //##################################################

    printf("\n\n##########Case3##########\n\n");
    unit_test(L3,L3_size);
    printf("Expected answer \n9");

    //##################################################

    printf("\n##########Case4##########\n\n");
    unit_test(L4,L4_size);
    printf("Expected answer \n");

    //#####################################################
    printf("\n\n");
    system("Pause");

    return 0;
}