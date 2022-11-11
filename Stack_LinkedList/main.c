#include <stdio.h>
#include "Stack.h"
int main() {
    Stack stack;

    initStack(&stack);
    for (int i = 1; i < 10; ++i) {
        push(&stack,i * 100);
    }
//    printStack(&stack);
    while (!isEmpty(&stack)) {
        printf("%d ", pop(&stack));   //将栈中所有元素依次出栈
    }
    printf("\n");
    return 0;
}
