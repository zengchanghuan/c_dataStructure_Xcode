//
// Created by 曾长欢 on 2022/11/9.
//

#ifndef DOUBLECIRCULARLINKEDLIST_DULINKLIST_H
#define DOUBLECIRCULARLINKEDLIST_DULINKLIST_H

#include <stdbool.h>

typedef int ElemType;

typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prev;
    struct DuLNode *next;
} DuLNode, *PDuLNode;

typedef struct {
    DuLNode *head;
    int size;//数据结点的个数，不含头结点
} DuLinkList;


void initDuList(DuLinkList *list);

void printList(const DuLinkList *list);

DuLNode * FindValue(DuLinkList *list,ElemType value);

bool insertPrev(DuLinkList *list,DuLNode *p,ElemType value);

//头插法 头结点后插入
void insertFront(DuLinkList *list,ElemType value);

void insertBack(DuLinkList *list,ElemType value);
#endif