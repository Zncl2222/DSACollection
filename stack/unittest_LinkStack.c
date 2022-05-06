# include <stdio.h>
# include <stdlib.h>
# include "Link_stack.h"


int main(){

    LinkStack S;

    CreateStack_Random(&S,10);

    StackTarvarse(&S);

    system("Pause");

    return 0;

}