//
// Created by 曾长欢 on 2022/11/11.
//
#include "Queue.h"

Node createNode(void) {
    Node node = malloc(sizeof(struct QueueNode));
    if (NULL != node) {
        memset(node, 0, sizeof(struct QueueNode));
    }
    return node;
}

bool initQueue(Queue queue) {
    Node node = createNode();
    if (NULL == node) {
        return false;
    }
    queue->front = queue->rear = node;
    return true;
}

//入队
bool enQueue(Queue queue, Element data) {
    Node node = createNode();
    if (NULL == node){
        return false;
    }

    node->data = data;
    queue->rear->next = node;
    queue->rear = node;
    return true;


}

//出队
Element deQueue(Queue queue){
    Element data = queue->front->next->data;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node){
        queue->rear = queue->front;
    }
    free(node);
    return data;
}

void printQueue(Queue queue){
    Node node =queue->front->next;
    while (1) {
        printf("%d ", node->data);
        if (node == queue->rear) {
            break;
        }  //当已经打印最后一个元素后，再结束
        else {
            node = node->next;
        }
    }
}

bool isEmpty(Queue queue){
    return queue->rear == queue->front;
}