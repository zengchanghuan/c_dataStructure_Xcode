//
//   LinkedList.c
//   LinkedList
//
//  Created by 曾长欢 on 2022/11/4.
//

#include "LinkedList.h"
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>     // 提供 strstr 原型
#include <assert.h>

//private method
ListNode * createNode(void){
    ListNode *sentinelNode = malloc(sizeof(ListNode));
    if(NULL == sentinelNode){
        return NULL;
    }
    memset(sentinelNode, 0, sizeof(ListNode));
    return  sentinelNode;
}

void FreeNode(ListNode *node){
    free(node);
}

//返回结点的前驱地址
ListNode *FindValuePrecursor(LinkList head,Element value){
    assert(head != NULL);
    ListNode *precursor = head;
    ListNode *p = head->next;
    
    while (p != NULL && p->element != value) {
        //两个指什依次往后遍历
        precursor = p;
        p = p->next;
    }
    if(NULL == p){
        precursor = NULL;
    }
    return precursor;
    
}

//返回结点地址
ListNode * initList(void){
    ListNode *head = createNode();
    head->next = NULL;
    return head;
    
}

void printList(LinkList head){
    assert(head != NULL);
    ListNode *p = head->next;
    while (p != NULL) {
        printf("%d ",p->element);
        p = p->next;
    }
    printf("\n");
    
}
bool insertList(LinkList head,Element element,int index);

bool deleteList(LinkList head,int index);

Element *getList(LinkList head,int index);

ListNode * findValue(LinkList head,Element value) {
    assert(head != NULL);
    ListNode *p = head->next;
    
    while (p != NULL && p->element != value) {
        p = p->next;
    }
    return p;
}

//按位查询返回结点 头结点序号为0，左边界
ListNode * findIndex(LinkList head,int index){
    assert(head != NULL);
    
    int i = 1;
    ListNode *p = head->next;
    
    //左边界判断
    if(index < 1){
        return NULL;
    }
    
    // 右边界判断
    while (p != NULL && i < index) {
        p = p->next;
        i = i + 1;
    }
    return p;
    
}
//按位查询返回结点前驱
ListNode * findIndexPrecursor(LinkList head,int index){
    assert(head != NULL);
    
    int i = 1;
    ListNode *pre = head;
    ListNode *p = head->next;
    
    if(index < 1){
        return NULL;
    }
    
    while (p != NULL && i < index) {
        pre = p;
        p = p->next;
        i = i + 1;
    }
    if(NULL == p){
        pre = NULL;
    }
    return pre;
}
int findList(LinkList head,Element value);

int length(LinkList list);


