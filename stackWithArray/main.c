#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    initStack(&stack);
    for (int i = 0; i < 10; ++i) {
        push(&stack,i);
    }

    int value;
    while (!isEmpty(&stack)){
        pop(&stack,&value);
        printf(" %d ",value);
    }
    printf("\n");
    return 0;
}
