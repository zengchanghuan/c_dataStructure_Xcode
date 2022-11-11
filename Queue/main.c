#include <stdio.h>
#include "Queue.h"

int main() {
     struct QueueNode queue;
    initQueue(&queue);
    for (int i = 1; i <= 10; ++i) {
        enQueue(&queue,i * 100);
    }
    printQueue(&queue);
    printf("\n");

    printf("***********\n");

    while (!isEmpty(&queue)) {
        printf("%d ", deQueue(&queue));
    }
    printf("\n");
    return 0;
}
