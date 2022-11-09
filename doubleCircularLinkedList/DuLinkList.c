//
// Created by 曾长欢 on 2022/11/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "DuLinkList.h"




DuLNode *createNode(void) {
    DuLNode *node = malloc(sizeof(DuLNode));
    if (node != NULL) {
        memset(node, 0, sizeof(DuLNode));

    }
    return node;
}


void initDuList(DuLinkList *list) {
    assert(list != NULL);
    list->size = 0;

    DuLNode *s = createNode();
    if (NULL == s) {
        exit(1);
    }

    s->prev = s;
    s->next = s;
    list->head = s;
}

void printList(const DuLinkList *list) {
    assert(list != NULL);
    //p 哨兵结点
    DuLNode *p = list->head->next;
    //循环条件和单链表不一样
    while (p != list->head) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");

}

DuLNode *FindValue(DuLinkList *list, ElemType value) {
    assert(list != NULL);
    DuLNode *p = list->head->next;
    while (p != list->head && p->data != value) {
        p = p->next;
    }
    if (p == list->head) {
        p = NULL;
    }
    return p;
}

Status insertPrev(DuLinkList *list, DuLNode *p, ElemType value) {
    assert(list != NULL);

    if (NULL == p) {
        return NULLPRT;
    }

    DuLNode *s = createNode();
    if (NULL == s) {
        return OVERFLOW;
    }

    s->data = value;

    s->prev = p->prev;
    s->next = p;
    p->prev = s;
    s->prev->next = s;

    list->size += 1;
    return true;
}

void insertFront(DuLinkList *list, ElemType value) {
    assert(list != NULL);
    insertPrev(list, list->head->next, value);
}

void insertBack(DuLinkList *list, ElemType value) {
    assert(list != NULL);
    insertPrev(list, list->head, value);

}

DuLNode *findIndex(const DuLinkList *list,int index){
    assert(list != NULL);
    if (index < 1 || index > list->size){
        return NULL;
    }

    DuLNode  *p = list->head->next;

    int i = 1;
    while (i < index){
        i += 1;
        p = p->next;
    }
    return p;
}

Status insertIndex(DuLinkList *list,int index,ElemType value){
    assert(list != NULL);
    return insertPrev(list, findIndex(list,index),value);
}

int getSize(const DuLinkList *list){
    assert(list != NULL);

    return list->size;
}

bool isEmpty(const DuLinkList *list){
    assert(list != NULL);
    return getSize(list) == 0;
}
