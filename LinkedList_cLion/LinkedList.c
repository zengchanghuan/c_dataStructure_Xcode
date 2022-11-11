//
// Created by 曾长欢 on 2022/11/10.
//

#include <stddef.h>
#include <stdlib.h>
#include <printf.h>
#include "LinkedList.h"

void initList(Node head){
    head->next = NULL;
}


void printList(Node head){
    while (head->next){
        head = head->next;
        printf("%d -> ",head->data);
    }
}
bool insert(Node head,Element data,int index){
    //左边界
    if(index < 1){
        return false;
    }

    //找前驱结点 这段代码可以单独提出来
    while (--index){
        head = head->next;
        //右边界
        if(head == NULL){
            return false;
        }
    }

    Node node = malloc(sizeof (Node));
    if (NULL == node){
        return false;
    }
    node->data = data;
    node->next = head->next;
    head->next = node;
    return true;

}

bool deleteIndex(Node head,int index){
    //左边界
    if(index < 1){
        return false;
    }

    while (--index){
        head = head->next;
        if (NULL == head){
            return false;
        }
    }

    if (head->next == NULL){
        return false;
    }

    Node temp = head->next;
    head->next = head->next->next;
    free(temp);
    return true;


}