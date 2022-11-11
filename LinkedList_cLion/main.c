#include <stdio.h>
#include "LinkedList.h"
int main() {
    Node  head;
    initList(&head);

    for (int i = 1; i <= 10; ++i) {
        insert(&head,i * 100,i);

    }
//    printList(&head);
    printf("\n");

//    deleteIndex(&head,5);
    printList(&head);
    printf("\n");

//    Node node = getList(&head,5);
    printf("getList %d", findList(&head,500));

    return 0;
}
