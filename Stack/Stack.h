//
// Created by 曾长欢 on 2022/11/11.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Element;

struct StackNode {
    Element *array;
    int capacity;
    int top;
};

typedef struct StackNode *Stack;

bool initStack(Stack stack);

bool push(Stack stack,Element data);

Element pop(Stack stack);

void printStack(Stack stack);

bool isEmpty(Stack stack);

#endif //STACK_STACK_H
