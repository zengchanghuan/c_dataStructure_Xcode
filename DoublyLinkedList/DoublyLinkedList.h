//
// Created by 曾长欢 on 2022/11/11.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Element;
struct DListNode {
    Element data;
    //后续
    struct DListNode *next;
    //前驱
    struct DListNode *prev;
};
typedef struct DListNode *Node;
typedef struct DListNode *DoublyLinkedList;

void initNode(Node node);

bool insertList(DoublyLinkedList head, Element element, int index);

#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
