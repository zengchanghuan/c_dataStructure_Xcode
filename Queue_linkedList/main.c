#include <stdio.h>
#include "Queue.h"

int main() {
    Queue queue;
    initQueue(&queue);
    for (int i = 1; i <= 5; ++i) {
        enQueue(&queue, i*100);
    }
    printQueue(&queue);

    printf("\n");
    while (!isEmpty(&queue)){
        printf("%d ", deQueue(&queue));
    }
}