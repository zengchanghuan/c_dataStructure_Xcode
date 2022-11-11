#include <stdio.h>
#include "Stack.h"

int main() {
    Stack  stack;
    initStack(&stack);
    for (int i = 0; i < 10; ++i) {
        push(&stack,i * 100);
    }

    printStack(&stack);

    printf("\n");
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));   //将栈中所有元素依次出栈
    }

    return 0;
}
