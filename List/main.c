#include <stdio.h>
#include <stdlib.h>
#include "List.h"
int main() {


    List * list = makelist();
    add(1, list);
    add(20, list);
    add(2, list);
    add(5, list);
    add(8, list);
    add(9, list);
    add(13, list);
    display(list);
    /*
    delete(2, list);
    display(list);
    delete(1, list);
    display(list);
    delete(20, list);
    display(list);
    reverse(list);
    printf("Reversed: using three pointers. \n");
    display(list);
    reverse_using_two_pointers(list);
    printf("Reversed: using to pointers. \n");
    display(list);
    destroy(list);
     */
    return 0;
}
