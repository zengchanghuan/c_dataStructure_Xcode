//
// Created by 曾长欢 on 2022/11/15.
//

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void insert2(struct node **head, int val) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    if (*head)
        new->next = *head;
    *head = new;

}

void insert(List *head, int val) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    if (*head) {
        new->next = *head;
    }
    *head = new;

}

void printList(List list) {
    while (list) {
        printf("%d->", list->data);
        list = list->next;
    }
}