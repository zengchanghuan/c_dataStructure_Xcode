#include <stdio.h>
#include <stdlib.h>
#include "List.h"







int main(){
    List list = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    printList(list);
}