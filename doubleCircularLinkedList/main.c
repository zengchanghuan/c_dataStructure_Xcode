#include <stdio.h>
#include "DuLinkList.h"
int main() {
    DuLinkList mylist;
    initDuList(&mylist);
    for (int i = 0; i < 15; ++i) {
        insertBack(&mylist,i+1);
        printList(&mylist);
    }
//    DuLNode *node = findIndex(&mylist,4);

    printf("insertIndex %d", insertIndex(&mylist,5,453));
    printList(&mylist);
    return 0;
}
