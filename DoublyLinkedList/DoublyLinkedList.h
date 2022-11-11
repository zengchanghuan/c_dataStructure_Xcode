//
// Created by 曾长欢 on 2022/11/11.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <stdbool.h>

typedef int Element;
struct DNode{
    Element data;
    struct DNode *next;
    struct DNode *prev;
};

typedef struct DNode *Node;

typedef struct DNode *DoublyLinkedList;

void initList(Node node);

bool insertList(DoublyLinkedList head,Element data,int index);
#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
