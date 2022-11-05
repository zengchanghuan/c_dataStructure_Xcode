//
//   LinkedList.h
//   LinkedList
//
//  Created by 曾长欢 on 2022/11/4.
//

#ifndef  LinkedList_h
#define  LinkedList_h

#include <stdio.h>
#include <stdbool.h>

typedef int Element;
//typedef struct ListNode{
//    Element element;
//    struct ListNode *next;
//}ListNode,*LinkList;



struct ListNode{
    Element element;
    struct ListNode *next;
};

//别名
typedef struct ListNode ListNode;
typedef struct ListNode *LinkList;


/// 初始化带头结点的链表
ListNode * initList(void);

bool insertList(LinkList head,Element element,int index);

bool deleteList(LinkList head,int index);

Element *getList(LinkList head,int index);

int findList(LinkList head,Element element);

int length(LinkList list);

void printList(LinkList head);

#endif /*  LinkedList_h */
