#include <stdio.h>
#include <stdlib.h>
#include "List.h"


int main() {
//    List list = NULL;
    Node list;
    initList(&list);
    for (int i = 1; i < 7; ++i) {
        insertBack(&list,i * 100);
    }
    printf("尾部插入\n");
    printList(list);
    printf("\n");
    deleteBack(&list);
    printList(list);
    printf("\n");
}
/*
int main2(){
    List list = NULL;

    insertBack(&list, 1);
    insertBack(&list, 2);
    insertBack(&list, 3);
    insertBack(&list, 4);
    insertBack(&list, 5);
    insertBack(&list, 6);
    printf("尾部插入\n");

    printList(list);
    printf("\n");

    List list2 = NULL;
    insertFront(&list2, 1);
    insertFront(&list2, 2);
    insertFront(&list2, 3);
    insertFront(&list2, 4);
    insertFront(&list2, 5);
    insertFront(&list2, 6);
    printf("头部插入\n");
    printList(list2);
    printf("\n");
}
*/