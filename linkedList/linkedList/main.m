//
//  main.m
//  linkedList
//
//  Created by 曾长欢 on 2022/11/4.
//

#import <Foundation/Foundation.h>
#import "LinkedList.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        LinkList head = initList();
//        for(int i = 0; i < 10; ++i){
//            insertBack(head, i*100);
//            insertList(head, i + 10, i);
//            insertBack(head, i + 10);
//
//            printList(head);
//        }
//        NSLog(@"**********************");
//        printList(head);
//        insertList(head, 342, 1);
//        insertList(head, 34242, 11);
//        printList(head);
//        NSLog(@"length = %d",length(head));

//        deleteWithValue(head, 19);
//        printList(head);

//        while (!isEmpty(head)) {
////            deleteFirst(head);
////            deleteLast(head);
//            printList(head);
//
//        }
        /*
        LinkList head2 = initList();
        for(int i = 1; i < 10; ++i){
            insertFront(head2, i * 100);
            printList(head2);

        }
        */


        LinkList head2 = initList();
//        int array[] = {3,43,43,43,324,54,43,323,43,43,3,64};
        int array[] = {1,2,3,4,5,6,7,8};

        int length = sizeof(array)/sizeof(array[0]);
        for (int i = 0; i < length; i++) {
            insertBack(head2, array[i]);
        }
        printList(head2);
        deleteWithAllValue(head2, 43);
//        clearList(head2);
        reverse(head2);
        printList(head2);
        reverse(head2);
        printList(head2);


        LinkList paritionHead = initList();
        for (int i = 0; i < 10; i++) {
            insertBack(paritionHead, rand()%100);
        }
        printList(paritionHead);
        
//        paritionHead->next = listPartition(paritionHead->next, 50);
        listQucikSort(paritionHead->next, NULL);
        printList(paritionHead);


    }
    return 0;
}
