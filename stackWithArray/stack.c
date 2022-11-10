//
// Created by 曾长欢 on 2022/11/10.
//
#include "stack.h"
#include <stdlib.h>
#include <assert.h>

Status initStack(Stack *stack){
    assert(stack != NULL);

    stack->base = malloc(sizeof (STACK_INIT_SIZE));
    if (NULL == stack->base){
        return OVERFLOW;
    }

    stack->top = stack->base;
    stack->size = STACK_INIT_SIZE;
    return OK;
}
