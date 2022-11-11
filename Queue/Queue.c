//
// Created by 曾长欢 on 2022/11/11.
//

#include "Queue.h"

bool initQueue(Queue queue) {
    queue->array = malloc(sizeof(Element) * 10);
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return true;
}

bool enQueue(Queue queue, Element data) {
    if ((queue->rear + 1) % queue->capacity == queue->front) {
        return false;
    }  //先判断队列是否已满，如果队尾下一个就是队首，那么说明已满
    queue->rear = (queue->rear + 1) % queue->capacity;   //队尾先向前移动一位，注意取余计算才能实现循环
    queue->array[queue->rear] = data;   //在新的位置插入元素
    return true;
}

//出队
Element deQueue(Queue queue) {
    //先将队首指针后移
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

bool isEmpty(Queue queue){
    return queue->rear == queue->front;
}

void printQueue(Queue queue) {
    int i = queue->front;   //遍历队列需要从队首开始
    do {
        i = (i + 1) % queue->capacity;   //先向后循环移动
        printf("%d ", queue->array[i]);  //然后打印当前位置上的元素
    } while (i != queue->rear);
}