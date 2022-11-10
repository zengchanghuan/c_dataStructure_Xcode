//
// Created by 曾长欢 on 2022/11/9.
//

#ifndef DOUBLECIRCULARLINKEDLIST_DULINKLIST_H
#define DOUBLECIRCULARLINKEDLIST_DULINKLIST_H
#define OVERFLOW -1

typedef int Status;
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

DuLNode * findValue(DuLinkList *list,ElemType value);

Status insertPrev(DuLinkList *list,DuLNode *p,ElemType value);

//头插法 头结点后插入
void insertFront(DuLinkList *list,ElemType value);

void insertBack(DuLinkList *list,ElemType value);

//按位查找
DuLNode *findIndex(const DuLinkList *list,int index);

//按位插入
Status insertIndex(DuLinkList *list,int index,ElemType value);

int getSize(const DuLinkList *list);

bool isEmpty(const DuLinkList *list);

Status delete(DuLinkList *list,DuLNode *prt);

//从头结点删
void deleteFront(DuLinkList *list);

void deleteBack(DuLinkList *list);

void clearList(DuLinkList *list);

void destroyList(DuLinkList *list);

//按值删除
bool deleteValue(DuLinkList *list,ElemType value);
#endif