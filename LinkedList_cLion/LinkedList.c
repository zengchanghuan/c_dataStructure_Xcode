//
// Created by 曾长欢 on 2022/11/10.
//

#include <stddef.h>
#include <stdlib.h>
#include <printf.h>
#include <assert.h>
#include "LinkedList.h"

void initList(LinkedList head) {
    head->next = NULL;
}

void printList(LinkedList head) {
    assert(head != NULL);
    while (head->next) {
        printf("%d->", head->next->data);
        head = head->next;
    }
}

bool insert(LinkedList head, Element data, int index) {
    assert(head != NULL);
    //左边界
    if (index < 1) {
        return false;
    }
    //找到要插入的位置
    int i = 1;
    Node p = head;
    while (p->next != NULL && i < index) {
        p = p->next;
        i = i + 1;
    }

    //右边界
    if (index > i) {
        return false;
    }
    Node node = malloc(sizeof(struct ListNode));
    node->data = data;

    //关键代码
    node->next = p->next;
    p->next = node;


}

bool deleteIndex(LinkedList head, int index) {
    assert(head != NULL);
    if (index < 1) {
        return false;
    }
    Node p = head;
    int i = 1;

    while (p->next != NULL && i < index) {
        p = p->next;
        i = i + 1;
    }
    Node temp = p->next;
    p->next = p->next->next;
    temp->next = NULL;
    free(temp);
    return true;
}

Element getListIndex2(LinkedList head, int index) {
    if (index < 1) {
        return false;
    }

    do {
        head = head->next;
        if (head == NULL) {
            return NULL;
        }
    } while (--index);
    return head->data;
}

Element getListIndex(LinkedList head, int index) {
    assert(head != NULL);
    if (index < 1) {
        return false;
    }
    Node p = head->next;
    int i = 1;
    while (p != NULL && i < index) {
        p = p->next;
        i = i + 1;
    }
    return p->data;
}
int findListValue(Node head, Element data){
    assert(head != NULL);
    int i = 1;
    while(head->next != NULL && head->next->data != data){
        head = head->next;
        i = i + 1;
    }
    return i;

}
int getSize(LinkedList head) {
    assert(head != NULL);
    int size = 0;
    while (head->next != NULL) {
        head = head->next;
        size = size + 1;
    }
    return size;
}
bool isEmpty(LinkedList head){
    assert(head != NULL);

    return head->next == NULL;
}

void clear(LinkedList head){
    assert(head != NULL);
    while (head->next != NULL){
        Node s = head->next;
        head->next = head->next->next;
        free(s);
    }
}

void destroy(LinkedList head){
    assert(head != NULL);
    clear(&head);
    head->next = NULL;
    free(head);
}
/* 第一版实现
void initList(LinkedList head) {
    head->next = NULL;
}

void printList(LinkedList head) {
    while (head->next) {
        head = head->next;
        printf("%d -> ", head->data);
    }
}

bool insert(LinkedList head, Element data, int index) {
    //左边界
    if (index < 1) {
        return false;
    }

    //找前驱结点 这段代码可以单独提出来
    while (--index) {
        head = head->next;
        //右边界
        if (head == NULL) {
            return false;
        }
    }

    Node node = malloc(sizeof(Node));
    if (NULL == node) {
        return false;
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    return true;

}

bool deleteIndex(LinkedList head, int index) {
    //左边界
    if (index < 1) {
        return false;
    }

    while (--index) {
        head = head->next;
        if (NULL == head) {
            return false;
        }
    }

    if (head->next == NULL) {
        return false;
    }

    Node temp = head->next;
    head->next = head->next->next;
    free(temp);
    return true;
}

Element  getListIndex(LinkedList head, int index) {
    if (index < 1) {
        return false;
    }

    do {
        head = head->next;
        if (head == NULL){
            return NULL;
        }
    } while (--index);
    return head->data;
}

int getSize(LinkedList head){
    int  i = 0;
    while (head->next){
        head = head->next;
        i++;
    }
    return i;
}

int findListValue(Node head, Element data){
    head = head->next;
    int i = 1;
    while (head){
        if (head->data == data){
            return i;
        }

        head = head->next;
        i++;
    }
    return -1;
}
*/