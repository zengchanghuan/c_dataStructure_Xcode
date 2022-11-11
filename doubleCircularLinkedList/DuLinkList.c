//
// Created by 曾长欢 on 2022/11/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "DuLinkList.h"




DuLNode *createNode(void) {
    DuLNode *node = malloc(sizeof(struct  DuLNode));
    if (node != NULL) {
        memset(node, 0, sizeof(struct DuLNode));

    }
    return node;
}

void freeNode(DuLNode *p){
    free(p);
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

DuLNode *findValue(DuLinkList *list, ElemType value) {
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
        return NULL;
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

Status delete(DuLinkList *list,DuLNode *prt){
    assert(list != NULL);

    if (NULL == prt){
        return NULL;
    }
    prt->prev->next = prt->next;
    prt->next->prev = prt->prev;
}

void deleteFront(DuLinkList *list){
    assert(list != NULL);
    delete(list,list->head->next);
}

void deleteBack(DuLinkList *list){
    assert(list != NULL);
    delete(list,list->head->prev);
}

void clearList(DuLinkList *list){
    assert(list != NULL);
    while (!isEmpty(list)){
        deleteFront(list);
    }
}

void destroyList(DuLinkList *list){
    assert(list != NULL);
    clearList(list);
    freeNode(list->head);
    list->head = NULL;
}

bool deleteValue(DuLinkList *list,ElemType value){
    assert(list != NULL);
    bool res = false;
    DuLNode  *p = findValue(list,value);
    if (p != NULL){
        delete(list,p);
        res = true;
    }
    return res;
}

//效率不够高 基础版
bool deleteAllEqualValue2(DuLinkList *list,ElemType value){
    assert(list != NULL);
    while (deleteValue(list,value));

}

//优化版
bool deleteAllEqualValue(DuLinkList *list,ElemType value){
    assert(list != NULL);
    DuLNode  * p = list->head->next;
    while (p != list->head){
        if (p->data == value){
            delete(list,p);
        }
        p = p->next;
    }

}

