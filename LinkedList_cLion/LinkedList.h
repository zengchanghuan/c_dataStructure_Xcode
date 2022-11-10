//
// Created by 曾长欢 on 2022/11/10.
//

#ifndef LINKEDLIST_CLION_LINKEDLIST_H
#define LINKEDLIST_CLION_LINKEDLIST_H

typedef  int Element;

struct ListNode{
    Element data;
    struct ListNode *next;
};

typedef struct ListNode *Node;

//typedef struct LinkedList{
//    Node head;
//} List;

void initList(Node head);

#endif //LINKEDLIST_CLION_LINKEDLIST_H
