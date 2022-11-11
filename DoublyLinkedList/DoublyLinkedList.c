//
// Created by 曾长欢 on 2022/11/11.
//
#include <stddef.h>
#include <stdlib.h>
#include <string.h>     // 提供 strstr 原型
#include "DoublyLinkedList.h"

void initList(Node node) {
    node->next = node->prev = NULL;
}

Node *createNode(void) {
    Node node = malloc(sizeof(Node));
    if (NULL != node) {
        memset(node, 0, sizeof(Node));
    }
    return node;
}

bool insertList(DoublyLinkedList head, Element data, int index) {
    if (index < 1) {
        return false;
    }

    while (--index) {
        head = head->next;
        if (NULL == head) {
            return false;
        }
    }

//    Node node = createNode();
    Node node = malloc(sizeof(Node));  //创建新的结点

    if (NULL == node) {
        return false;
    }
    node->data = data;

    if (head->next != NULL) {
//        node->next = head->next;
//        head->next->prev = node;
        head->next->prev = node;
        node->next = head->next;
    } else {
        node->next = NULL;
    }
    head->next = node;
    node->prev = head;
    return true;

}
