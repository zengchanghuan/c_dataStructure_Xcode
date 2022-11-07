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

//判空
bool isEmpty(LinkList head);

//返回结点的个数
int length(LinkList list);

//按值查询
ListNode * findValue(LinkList head,Element value);

//按值查询，返回前驱地址
ListNode *FindValuePrecursor(LinkList head,Element value);

//按位查询返回结点
ListNode * findIndex(LinkList head,int index);

//按位插入
bool insertList(LinkList head,Element element,int index);

Element *getList(LinkList head,int index);

int findList(LinkList head,Element element);

void printList(LinkList head);

//尾插法
void insertBack(LinkList head,Element value);

//头插法
void insertFront(LinkList head,Element value);

//删除prt的后续结点
bool deleteNext(LinkList head,ListNode *ptr);

//从首元素删除链表元素
void deleteFront(LinkList head);

//从尾部删除链表元素
void deleteBack(LinkList head);

//按位删除
bool deleteWithIndex(LinkList head,int index);

//按值删除
bool deleteWithValue(LinkList head,Element value);

//删除所有与所给值相等的结点
void deleteWithAllValue(LinkList head,Element value);

//清空元素 保留头结点
void clearList(LinkList head);

//销毁链表 头结点亦删除
void destroyList(LinkList head);

//链表转置
void reverse(LinkList head);
#endif /*  LinkedList_h */
