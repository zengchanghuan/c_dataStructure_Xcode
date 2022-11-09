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

//不带头结点的反转链表方法 递归法
ListNode *reverseNoHead2(ListNode *p){
    if(p == NULL || p->next == NULL){
        return p;
    }
    
    ListNode *firstNode = reverseNoHead2(p->next);
    p->next->next = p;
    p->next = NULL;
    return firstNode;
}

//不带头结点的反转链表方法 三指针法

ListNode *reverseNoHead3(LinkList head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *pre = NULL;
    ListNode *s = NULL;
    ListNode *p = head;
    
    while (p != NULL) {
        s = p;
        p = p->next;
        s->next = pre;
        pre = s;
    }
    
    return pre;
}

//不带头结点的反转链表方法
void reverseNoHead(LinkList head){
    assert(head != NULL);
    
    ListNode *current,*prev,*next;
    current = head;
    prev = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
}

//返回链表中间结点
ListNode * listMid(LinkList head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    int n = 0;
    ListNode *p = head;
    
    while (p != NULL) {
        n = n + 1;
        p = p->next;
    }
    p = head;
    for (int i = 0; i < n/2; i++) {
        p = p->next;
    }
    return p;
}

//返回链表中间结点 快慢指针
ListNode * listMid2(LinkList head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        if (NULL == fast) {
            break;
        }
        fast = fast->next;
    }
    return slow;
}

//链表中倒数第k个节点
void printList_k_c(LinkList head,int k){
    if (head == NULL || k < 1) {
        return;
    }
    
    ListNode *p = head;
    ListNode *cur = head;
    while (p != NULL && k--) {
        p = p->next;
    }
    if (NULL == p) {
        return;
    }
    while (p != NULL) {
        cur = cur->next;
        p = p->next;
    }
    printf("%d \n",cur->element);
}

//判断单链表是否有环，有环返回环的起点
bool isCycle(LinkList head){
    bool res = true;
    if(head == NULL){
        return !res;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            res = false;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    
    
    return res;
}

ListNode *getCycleBegin(LinkList head) {
    if (head == NULL) {
        return NULL;
    }
    
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return NULL;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    //快 慢都可以
    return slow;
    
}

//暴力法
ListNode *getIntersectNode2(LinkList headA,LinkList headB)
{
    if(headA == NULL || headB == NULL || headA->next == NULL || headB->next == NULL){
        return NULL;
    }
    ListNode *pa = headA->next;
    while (pa != NULL) {
        ListNode *pb = headB->next;
        while (pb != NULL && pb != pa) {
            pb = pb->next;
        }
        if (pb == pa) {
            return pa;
        }
        pa = pa->next;
    }
    return NULL;
}

//获取公共结点再处理 有暇 待测试
ListNode *getIntersectNode4(LinkList headA,LinkList headB){
    if(headA == NULL || headB == NULL || headA->next == NULL || headB->next == NULL){
        return NULL;
    }
    
    ListNode *pa = headA->next;
    ListNode *pb = headB->next;
    
    while (pa != pb) {
        if (pa ==  NULL) {
            pa = headB->next;
            pa = pa->next;
        }
        if(pb == NULL){
            pb = headA->next;
            pb = pb->next;
        }
    }
    return pa;
    
}
ListNode *getIntersectNode3(LinkList headA,LinkList headB){
    if(headA == NULL || headB == NULL || headA->next == NULL || headB->next == NULL){
        return NULL;
    }
    
    int lengthA = length(headA);
    int lengthB = length(headB);
    
    ListNode *pa = headA->next;
    ListNode *pb = headB->next;
    
    while (lengthA > lengthB) {
        pa = pa->next;
        --lengthA;
    }
    while (lengthB > lengthA) {
        pb = pb->next;
        lengthB--;
    }
    
    while (pa != NULL && pb  != NULL && pa != pb) {
        pa = pa->next;
        pb = pb->next;
    }
    
    return pa;
    
    
}
ListNode *Reverse(ListNode *p){
    if (p == NULL || p->next == NULL) {
        return p;
    }
    
    ListNode *fn = Reverse(p->next);
    p->next->next = p;
    p->next = NULL;
    return fn;
}

//递归法
void reverse(LinkList head){
    assert(head != NULL);
    
    //加上这个更好
    if (head->next == NULL || head->next->next == NULL){
        return;
    }
    ListNode *p = head->next;
    head->next = Reverse(p);
}
//利用stack反转链表 2N
void reverse5(LinkList head){
    assert(head != NULL);
    
    //加上这个更好
    if (head->next == NULL || head->next->next == NULL){
        return;
    }
    
    int lenth = 0;
    ListNode *p = head->next;
    while (p != NULL) {
        lenth++;
        p = p->next;
    }
    int *stack = (int *)malloc(sizeof(int)*lenth);
    int top = -1;
    p = head->next;
    
    while (p != NULL) {
        top += 1;
        stack[top] = p->element;
        p = p->next;
    }
    p = head->next;
    
    while (p != NULL) {
        p->element = stack[top];
        top = top - 1;
        p = p->next;
    }
    free(stack);
    stack = NULL;
    
}
//头插法反转链表
void reverse4(LinkList head){
    assert(head != NULL);
    
    //加上这个更好
    if (head->next == NULL || head->next->next == NULL){
        return;
    }
    
    ListNode *p = head->next;
    head->next = NULL;
    
    while (p != NULL) {
        Element value = p->element;
        p = p->next;
        insertFront(head, value);
    }
    
}
//二指针法
void reverse2(LinkList head){
    assert(head != NULL);
    
    //加上这个更好
    if (head->next == NULL || head->next->next == NULL){
        return;
    }
    
    
    ListNode *s = NULL;
    ListNode *p = head->next;
    head->next = NULL;
    while (p != NULL) {
        s = p;
        p = p->next;
        s->next = head->next;
        head->next = s;
        
    }
    
}
//三指针法
void reverse3(LinkList head){
    assert(head != NULL);
    
    //加上这个更好
    if (head->next == NULL || head->next->next == NULL){
        return;
    }
    
    ListNode *pre = NULL;
    ListNode *s = NULL;
    ListNode *p = head->next;
    
    while (p != NULL) {
        s = p;
        p = p->next;
        s->next = pre;
        pre = s;
    }
    head->next = pre;
}

//不带头结点单链表 旋转
ListNode * rotateRight(LinkList head,int k){
    if (head == NULL || head->next) {
        return head;
    }
    
    int n = 1;
    ListNode *p = head;
    while (p->next != NULL) {
        n += 1;
        p = p->next;
    }
    int mov = n - k;
    while (mov--) {
        p = p->next;
    }
    head = p->next;
    p->next = NULL;
    return head;
}

ListNode * listPartition(LinkList head,Element x){
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    ListNode *pre = createNode();
    ListNode *newHead = createNode();
    
    pre->next = head;
    head = pre;
    newHead->next = NULL;
    
    ListNode *p= pre->next;
    ListNode *s = newHead;
    
    while (p != NULL) {
        if (p->element >= x) {
            
            pre->next = p->next;
            p->next = NULL;// s->next = null
            s->next = p;
            s = s->next;
            p = pre->next;
        } else {
            p = p->next;
            pre = pre->next;
        }
       
    }
    pre->next = newHead->next;
    pre = head;
    head = head->next;
    
    free(pre);
    pre = NULL;
    free(newHead);
    newHead = NULL;
    
    return head;
}

ListNode * parition(ListNode *beginNode,ListNode *endNode){
    if (beginNode == endNode || beginNode->next == endNode) {
        return beginNode;
    }
    ListNode *slow = beginNode;
    ListNode *fast = beginNode->next;
    int temp = beginNode->element;
    
    while (fast != endNode) {
        if (fast->element <= temp) {
            slow = slow->next;
            swap(&slow->element, &fast->element);
        }
        fast = fast->next;
    }
    swap(&slow->element, &beginNode->element);
    return slow;
}
//单链表快排
void listQucikSort(ListNode *begin,ListNode *end){
    if (begin == end || begin->next == end) {
        return;
    }
    
    ListNode *pmid = parition(begin, end);
    listQucikSort(begin, pmid);
    listQucikSort(pmid->next,end);
    
    
}
