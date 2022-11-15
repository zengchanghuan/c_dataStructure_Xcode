//
// Created by 曾长欢 on 2022/11/15.
//

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertFront2(struct node **head, int val) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    if (*head)
        new->next = *head;
    *head = new;

}
void insertBack(List *pHead, int data) {
    assert(pHead);
    if(NULL == *pHead)
    {
        *pHead = (Node)malloc(sizeof(Node));
        (*pHead)->data = data;
        (*pHead)->next = NULL;
    }
    else
    {

        Node NewNode,tag;
        NewNode = (Node)malloc(sizeof(Node));		//创造新结点
        NewNode->data = data;
        NewNode->next = NULL;
        tag = *pHead;
        while(tag->next)
        {
            tag = tag->next;
        }
        tag->next = NewNode;

    }
}
void insertFront(List *list, int val) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;

//    printf("*list 指针（地址）的值为：OX%p\n", *list);

    if (*list) {
        new->next = *list;
    }
    *list = new;
}

void printList(List list) {
    while (list) {
        printf("%d->", list->data);
//        printf("\n");
//        printf("OX%p -> ", list);

//        printf("*list 指针（地址）的值为：OX%p\n",*list);

        list = list->next;
    }
}