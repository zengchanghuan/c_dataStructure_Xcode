//
// Created by 曾长欢 on 2022/11/11.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int Element;

struct QueueNode {
    Element *array;
    int capacity;   //数组容量
    int rear, front;   //队尾、队首指针
};

typedef struct QueueNode *Node;
typedef struct QueueNode *Queue;

bool initQueue(Queue queue);

//入队
bool enQueue(Queue queue,Element data);

//出队
Element deQueue(Queue queue);

void printQueue(Queue queue);

bool isEmpty(Queue queue);
#endif //QUEUE_QUEUE_H
