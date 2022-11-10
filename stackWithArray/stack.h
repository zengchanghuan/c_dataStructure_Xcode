//
// Created by 曾长欢 on 2022/11/10.
//

#ifndef STACKWITHARRAY_STACK_H
#define STACKWITHARRAY_STACK_H

#include <stdbool.h>
#define STACK_INIT_SIZE 100
#define STACKINC 1.4
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define PTRNULL -3
typedef int Status;
typedef int ElementType;
typedef struct {
    //栈底指针
    ElementType *base;
    //栈顶指针
    ElementType *top;
    //容量 非数据元素个数
    int size;

} Stack;

Status initStack(Stack *stack);

Status push(Stack *stack,ElementType value);

Status pop(Stack *stack, ElementType *pvalue);

Status getTop(Stack *stack, ElementType *pvalue);

int getLength(const Stack *stack);

bool isEmpty(const Stack *stack);

bool isFull(const Stack *stack);

void destroyStack(Stack *stack);

void clearStack(Stack *stack);

#endif //STACKWITHARRAY_STACK_H
