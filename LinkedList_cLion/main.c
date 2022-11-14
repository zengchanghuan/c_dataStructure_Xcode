#include <stdio.h>
#include "LinkedList.h"

int main() {
    Node head;
    initList(&head);

    for (int i = 1; i <= 10; ++i) {
        insert(&head, i * 100, i);

    }
//    printList(&head);
    printf("\n");
//    printList(&head);
//    printf("\n");


//    deleteIndex(&head,11);

//    int data = getListIndex(&head, 2);
//    printf("= getList %d ", data);
    printf(" size = %d", getSize(&head));
    printf("\n");

    printList(&head);


//    Node node = getList(&head,5);
    printf("\n");

    printf("findListValue %d", findListValue(&head,1000));

    return 0;
}
