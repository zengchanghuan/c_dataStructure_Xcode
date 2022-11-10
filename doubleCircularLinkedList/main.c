#include <stdio.h>
#include "DuLinkList.h"
int main() {
    DuLinkList mylist;
    initDuList(&mylist);
    for (int i = 0; i < 15; ++i) {
        insertBack(&mylist,i+1);
        printList(&mylist);
    }


    printf("insertIndex %d", insertIndex(&mylist,5,453));
    printf("insertIndex %d", insertIndex(&mylist,9,453));

    printList(&mylist);
//    DuLNode *node = findIndex(&mylist,5);

//    deleteFront(&mylist);
//    delete(&mylist,node);

    deleteAllEqualValue(&mylist,453);

    printList(&mylist);
    return 0;
}
