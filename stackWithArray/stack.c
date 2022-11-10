//
// Created by 曾长欢 on 2022/11/10.
//
#include "stack.h"
#include <stdlib.h>
#include <assert.h>

Status initStack(Stack *stack) {
    assert(stack != NULL);

    stack->base = malloc(sizeof(STACK_INIT_SIZE));
    if (NULL == stack->base) {
        return OVERFLOW;
    }

    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
    return OK;

}

Status push(Stack *stack, ElementType value) {
    assert(stack != NULL);
    if (isFull(stack)){
        return ERROR;
    }
    *stack->top = value;
    stack->top += 1;
    return OK;
}

Status pop(Stack *stack, ElementType *pvalue) {
    assert(stack != NULL);

    if (isFull(stack)) {
        return ERROR;
    }

    stack->top -= 1;
    *pvalue = *stack->top;
    return OK;

}

Status getTop(Stack *stack, ElementType *pvalue) {
    assert(stack != NULL);
    if (isEmpty(stack)){
        return ERROR;
    }
    if (pvalue == NULL) {
        return PTRNULL;
    }

    *pvalue = *stack->top - 1;
    return OK;
}

int getLength(const Stack *stack) {
    assert(stack != NULL);
    return stack->top - stack->base;
}


bool isEmpty(const Stack *stack) {
    assert(stack != NULL);

    return getLength(stack) == 0;
//    return stack->top == stack->base;
}

bool isFull(const Stack *stack) {
    assert(stack != NULL);
    return getLength(stack) == stack->size;

}

void destroyStack(Stack *stack) {
    assert(stack != NULL);

    free(stack->base);
    stack->base = NULL;
    stack->top = NULL;
    stack->size = 0;
}

void clearStack(Stack *stack) {
    assert(stack != NULL);
    stack->top = stack->base;
}