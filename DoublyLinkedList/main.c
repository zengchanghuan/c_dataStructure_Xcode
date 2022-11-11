#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    struct DNode head;
    initList(&head);
    for (int i = 0; i < 5; i++) {
        insertList(&head, i * 100, i);
    }
    Node node = &head;
//    do {
//        node = node->next;
//        printf("%d -> ", node->data);
//    } while (node->next != NULL);
//    printf("\n");
//再来反向遍历一次
    do {
        printf("%d -> ", node->data);
        node = node->prev;
    } while (node->prev != NULL);
    printf("\n");
//    printf("sizeList = %d \n", sizeList(&head));
    return 0;
}
