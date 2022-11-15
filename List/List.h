//
// Created by 曾长欢 on 2022/11/15.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
typedef int Element;
struct node{
    Element data;
    struct node *next;
};
//注意使用二级指针的地方
typedef struct node *Node;
typedef Node List;

//初始化链表
void initList(List *list);

// 在链表尾部插入
void insertBack(List *list, int data);

//删除链表最后一个节点
void deleteBack(List *list);

//在链表头部插入
void insertFront(List *list, int data);

void printList(List list);

/*
List * makelist();
void add(int data, List * list);
void delete(int data, List * list);
void display(List * list);
void reverse(List * list);
void reverse_using_two_pointers(List * list);
void destroy(List * list);
*/
#endif //LIST_LIST_H
