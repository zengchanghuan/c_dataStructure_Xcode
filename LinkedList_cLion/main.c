#include <stdio.h>
#include "LinkedList.h"
int main() {
    Node  head;
    initList(&head);

    for (int i = 1; i <= 10; ++i) {
        insert(&head,i * 100,i);

    }
    printList(&head);

    printf("\n");
    return 0;
}
