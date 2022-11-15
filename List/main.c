#include <stdio.h>
#include <stdlib.h>
#include "List.h"







int main(){
    struct node *head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    print_list(head);
}