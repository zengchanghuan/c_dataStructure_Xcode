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

bool isEmpty(LinkList head){
    assert(head != NULL);
    
    return head->next == NULL;
}
int length(LinkList head){
    assert(head != NULL);
    int length = 0;
    ListNode *p = head->next;
    while (p != NULL) {
        length = length + 1;
        p = p->next;
    }
    return length;
    
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

bool insertNext(LinkList head,ListNode *prt,Element value){
    assert(head != NULL);
    if(NULL == prt){
        return false;
    }
    ListNode *s = createNode();
    s->element = value;
    
    s->next = prt->next;
    prt->next = s;
    return true;
    
}

//头插法 基础版
void insertFront2(LinkList head,Element value){
    ListNode *s = createNode();
    s->element = value;
    
    s->next = head->next;
    head->next = s;
    
}

//头插法 优化版
void insertFront(LinkList head,Element value){
    assert(head != NULL);
    insertNext(head, head, value);
}
//尾插法
void insertBack(LinkList head,Element value){
    assert(head != NULL);
    
    ListNode *p = head;
    
    while (p->next != NULL) {
        p = p->next;
    }
    insertNext(head, p, value); 
    
    
}
//按位插入 基础版
bool insertList(LinkList head,Element value,int index){
    assert(head != NULL);
    
    //左边界
    if (index < 1) {
        return false;
    }
    
    int i = 1;
    ListNode *p = head;
    while (p->next != NULL && i < index) {
        p = p->next;
        i = i+1;
    }
    //右边界
    if (index > i) {
        return false;
    }
    return insertNext(head, p, value);
    
}

//按位插入 优化版
//bool insertList(LinkList head,Element value,int index){
//    assert(head != NULL);
//
//    //左边界
//    if (index < 1) {
//        return false;
//    }
//
//    int i = 1;
//    ListNode *p = head;
//    while (p->next != NULL && i < index) {
//        p = p->next;
//        i = i+1;
//    }
//    //右边界
//    if (index > i) {
//        return false;
//    }
//    return insertNext(head, p, value);
//
//}

//删除prt的后续结点
bool deleteNext(LinkList head,ListNode *ptr){
    assert(head != NULL);
    if (NULL == ptr || NULL == ptr->next) {
        return false;
    }
    ListNode *q = ptr->next;
    ptr->next = q->next;
    FreeNode(q);
    q = NULL;
    return true;
    
}

//删除链表首元素
void deleteFront(LinkList head){
    assert(head != NULL);
    deleteNext(head, head);
}

void deleteBack(LinkList head){
    assert(head != NULL);
    ListNode *pre = head;
    ListNode *p = head->next;
    while (p->next != NULL) {
        pre = p;
        p = p->next;
    }
    deleteNext(head, pre);
    
}
bool deleteWithIndex(LinkList head,int index);

//按值删除 基础版
bool deleteWithValue2(LinkList head,Element value){
    assert(head != NULL);
    bool res = false;
    ListNode *pre = head;
    ListNode *p = head->next;//第一个数据结点
    
    //先找到结点
    while (p != NULL && p->element != value) {
        pre = p;
        p = p->next;
    }
    
    if (p != NULL) {
        pre->next = p->next;
        FreeNode(p);
        p = NULL;
        res = true;
    }
    
    return res;

}

//按值删除 优化版
bool deleteWithValue(LinkList head,Element value){
    assert(head != NULL);
    return deleteNext(head, FindValuePrecursor(head, value));
}

//删除所有与所给值相等的结点 o^2复杂度
void deleteWithAllValue2(LinkList head,Element value){
    assert(head != NULL);
    ListNode *p = NULL;
    while ((p = FindValuePrecursor(head, value)) != NULL) {
        deleteNext(head, p);
    }
}

void swap(int *xp, int *yp)
{
    assert(xp != NULL && yp != NULL);
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void deleteWithAllValue(LinkList head,Element value){
    assert(head != NULL);
    
    ListNode *pre = head;
    ListNode *p = head->next;
    while (p != NULL) {
        if (p->element != value) {
            pre = pre->next;
            swap(&pre->element,&p->element);
        }
        p = p->next;
    }
    
    while (pre->next != NULL) {
        deleteNext(head, pre);
    }
}

Element *getList(LinkList head,int index);

//基础版
ListNode * findValue2(LinkList head,Element value) {
    assert(head != NULL);

    ListNode *p = head->next;
    
    while (p != NULL && p->element != value) {
        p = p->next;
    }
    return p;
}

//优化版
ListNode * findValue(LinkList head,Element value) {
    assert(head != NULL);
    ListNode *p = FindValuePrecursor(head, value);
    if (p != NULL) {
        p = p->next;
    }
    return p;
}

//按位查询返回结点 基础版
//头结点序号为0，左边界
ListNode * findIndex2(LinkList head,int index){
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

//按位查询返回结点 优化版
ListNode * findIndex(LinkList head,int index){
    assert(head != NULL);
    ListNode *p = FindValuePrecursor(head, index);
    if (p != NULL) {
        p = p->next;
    }
    return p;
    
}
//按位查询返回结点前驱 基础版
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

//清空元素 基础版
void clearList2(LinkList head){
    assert(head != NULL);
    
    while (head->next != NULL) {
        ListNode *q = head->next;
        head->next = q->next;
        FreeNode(q);
    }
}
//清空元素 优化版
void clearList(LinkList head){
    assert(head != NULL);

    while (!isEmpty(head)) {
        deleteFront(head);
    }
}

//销毁链表
void destroyList(LinkList head){
    assert(head != NULL);
    clearList(head);
    FreeNode(head);
}





