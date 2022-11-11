//
// Created by 曾长欢 on 2022/11/11.
//
#include "Stack.h"
bool initStack(Stack stack){
    stack->array = malloc(sizeof (Element) * 10);
    if (stack->array == NULL){
        return false;
    }
    stack->capacity = 10;
    stack->top = -1;
    return true;
}
bool push(Stack stack,Element data){
//    stack->array[stack->top + 1] = data;
//    stack->top++;
//    return true;
    if (stack->top + 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        Element *newArray = realloc(stack->array, newCapacity * sizeof(Element));
        if (newCapacity == NULL) {
            return false;
        }
        stack->array = newArray;
        stack->capacity = newCapacity;

    }
    stack->array[stack->top + 1] = data;
    stack->top++;
    return true;
}

Element pop(Stack stack){
    return stack->array[stack->top--];
}

void printStack(Stack stack) {
    for (int i = 0; i < stack->top + 1; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

}

bool isEmpty(Stack stack){
    return stack->top == -1;
}