//
// Created by 曾长欢 on 2022/11/10.
//

#ifndef LINKEDLIST_CLION_LINKEDLIST_H
#define LINKEDLIST_CLION_LINKEDLIST_H

#include <stdbool.h>

typedef  int Element;

struct ListNode{
    Element data;
    struct ListNode *next;
};

typedef struct ListNode *Node;

typedef struct ListNode *LinkedList;

void initList(LinkedList head);

bool insert(LinkedList head,Element data,int index);

bool deleteIndex(LinkedList head,int index);

Element getListIndex(LinkedList head, int index);

int getSize(LinkedList head);

int findListValue(Node head, Element element);

void printList(LinkedList head);

bool isEmpty(LinkedList head);

void clear(LinkedList head);

void destroy(LinkedList head);

#endif //LINKEDLIST_CLION_LINKEDLIST_H
