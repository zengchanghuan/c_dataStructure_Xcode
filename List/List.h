//
// Created by 曾长欢 on 2022/11/15.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H
typedef struct node Node;

typedef struct list List;

List * makelist();
void add(int data, List * list);
void delete(int data, List * list);
void display(List * list);
void reverse(List * list);
void reverse_using_two_pointers(List * list);
void destroy(List * list);

#endif //LIST_LIST_H
