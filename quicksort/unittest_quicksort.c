# include <stdio.h>
# include "quicksort.h"

int unit_test(int* array, int array_size){

    printf("Before\n");
    PrintArray(array,array_size);

    quicksort(array,0,array_size-1);

    printf("After\n");
    PrintArray(array,array_size);
}

int main(){

    // Test case

    int array1[]={9,6,8,1,2,4};                                // answer 1 2 4 6 8 9
    int array2[]={6,6,6,1,2,5,1,2,1,-5};                       // answer -5 1 1 1 2 2 5 6 6 6
    int array3[]={9};                                          // answer 9
    int array4[]={};                                           // answer NULL
    int array5[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};      // answer 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

    int array1_size=6;
    int array2_size=10;
    int array3_size=1;
    int array4_size=0;
    int array5_size=16;

    printf("Unit test (quick sort)");
    ///##################################################

    printf("\n\n##########Case1##########\n\n");
    unit_test(array1,array1_size);
    printf("Expected answer \n1 2 4 6 8 9");

    //##################################################

    printf("\n\n##########Case2##########\n\n");
    unit_test(array2,array2_size);
    printf("Expected answer \n-5 1 1 1 2 2 5 6 6 6");

    //##################################################

    printf("\n\n##########Case3##########\n\n");
    unit_test(array3,array3_size);
    printf("Expected answer \n9");

    //##################################################

    printf("\n##########Case4##########\n\n");
    unit_test(array4,array4_size);
    printf("Expected answer \n");

    //##################################################

    printf("\n##########Case5##########\n\n");
    unit_test(array5,array5_size);
    printf("Expected answer \n0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15");

    //#####################################################
    printf("\n\n");
    system("Pause");

    return 0;
}