//
// Created by 曾长欢 on 2022/11/11.
//
#include "Stack.h"

Node createNode(void ){
    Node node = malloc(sizeof (struct StackNode));
    if (NULL != node){
        memset(node,0,sizeof (struct StackNode));
    }
    return node;
}

bool initStack(Node head){
    head->next = NULL;
}

bool push(Stack stack,Element data){
    Node node = createNode();
    if (NULL == node){
        return false;
    }

    node->next = stack->next;
    node->data = data;
    stack->next = node;
    return true;
}

Element pop(Stack stack){
    Node top = stack->next;
    stack->next = stack->next->next;
    Element data = top->data;
    free(top);
    return data;
}

void printStack(Node head){
    head = head->next;
    while (head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
bool isEmpty(Stack stack){
    return stack->next == NULL;
}