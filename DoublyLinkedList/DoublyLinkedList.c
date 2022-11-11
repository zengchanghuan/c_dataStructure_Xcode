//
// Created by 曾长欢 on 2022/11/11.
//
#include "DoublyLinkedList.h"
#include <string.h>

void initNode(Node node) {
    node->next = node->prev = NULL;
}

Node createNode(void) {
    Node node = malloc(sizeof(struct DListNode));
    if (NULL != node) {
        memset(node, 0, sizeof(struct DListNode));
    }
    return node;
}

bool insertList(Node head, Element element, int index) {
    if (index < 1) {
        return false;
    }  //跟单链表一样，还是先找到对应的位置
    while (--index) {
        head = head->next;
        if (head == NULL) {
            return false;
        }
    }
//    Node *node = malloc(sizeof(Node));  //创建新的结点
    Node node = createNode();
    if (node == NULL) {
        return false;
    }
    node->data = element;

    if (head->next) {   //首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
        head->next->prev = node;   //如果存在则修改对应的两个指针
        node->next = head->next;
    } else {
        node->next = NULL;   //不存在直接将新结点的后继指针置为NULL
    }

    head->next = node;   //接着是前驱结点，直接操作就行
    node->prev = head;
    return true;
}

bool deleteIndex(DoublyLinkedList head,int index){
    if (index < 1){
        return false;
    }

    while (--index){
        head = head->next;
        if (NULL == head){
            return false;
        }
    }

    Node temp = head->next;

    if (head->next->next){
        head->next->next->prev = head;
        head->next = head->next->next;
    } else{
        head->next = NULL;
    }
    free(temp);
    return true;
}