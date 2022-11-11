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
//此重命名需要注意是否带*号,带*号直接用结构体申请内存，malloc(sizeof(struct DListNode))
typedef struct DListNode *Node;
typedef struct DListNode *DoublyLinkedList;

void initNode(Node node);

bool insertList(DoublyLinkedList head, Element element, int index);

bool deleteIndex(DoublyLinkedList head,int index);
#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
