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

typedef struct node *Node;
typedef Node List;

void initList(List *list);
//在链表头部插入
void insertFront(List *list, int val);

// 在链表尾部插入
void insertBack(List *list, int val);

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
