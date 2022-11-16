//
// Created by 曾长欢 on 2022/11/15.
//

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

bool DeleteNextLNode(Node p);

void insertFront2(struct node **head, int val) {
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    if (*head)
        new->next = *head;
    *head = new;

}

void initList(List *list) {
    assert(list);
    *list = NULL;
}

void insertBack(List *list, int data) {
    assert(list);
    if (NULL == *list) {
        *list = (Node) malloc(sizeof(Node));
        (*list)->data = data;
        (*list)->next = NULL;
    } else {

        Node NewNode, tag;
        NewNode = (Node) malloc(sizeof(Node));        //创造新结点
        NewNode->data = data;
        NewNode->next = NULL;
        tag = *list;
        while (tag->next) {
            tag = tag->next;
        }
        tag->next = NewNode;

    }
}

void deleteBack(List *list) {
    assert(list);
    Node pre = *list;
    Node cur = pre->next;

    if (NULL == *list) {
        return;
    }

    if (NULL == (*list)->next) {
        free(*list);
        *list = NULL;
    } else {
        while (cur->next) {
            pre = cur;
            cur = cur->next;
        }
        free(cur);
        pre->next = NULL;
    }


}

void insertFront(List *list, int val) {
    assert(list);
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    if (*list) {
        new->next = *list;
    }
    *list = new;
}

void deleteFront(List *list) {
    assert(list);
    Node pre = *list;
    Node cur = pre->next;
    if (NULL == *list) {
        return;
    }
    *list = cur;
    free(pre);
}

Node Find2(List list, Element data) {
    assert(list);
    Node tag;
    tag = list;
    while (tag) {
        if (data == tag->data) {
            return tag;
        }
        tag = tag->next;
    }
    return NULL;
}
Node Find(List *list, Element data) {
    assert(list);
    Node pre = *list;
    Node cur= pre->next;
    if (NULL == pre){
        return NULL;
    } else {
        while (cur->data != data && cur->next != NULL){
            pre = cur;
            cur = pre->next;
        }
        if (NULL== cur->next){
            return NULL;
        }
    }
}

bool insertIndex(List list, int index, Element e) {
    if (index < 1) {
        // i值不合法，返回false
        return false;
    }
    Node p = list;
    int j = 0;    //计数
    while (p && j < index - 1) {
        p = p->next;
        j++;
    }
    if (!p) {    // i值不合法：超过表长度
        return false;
    }
    Node s = malloc(sizeof(Node));
// 注：以下三行代码中有顺序要求。
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(List L, int i/*,int &e*/) {
    if (i < 1) {//位序小于1，则报错
        return false;
    }
    Node p, q;
    p = L;    //指针p为当前扫描的结点,L指向第一个结点
    int j = 1;    //j的值代表p指向的是第几个结点
    if (i == 1) { //对删除第一个结点的特殊情况
        q = L->next;
        free(p);
        L = q;
        return true;
    }
    while (p != NULL && j < i - 1) {
        p = p->next;  //循环找到i-1个结点，且该结点为不为空
        j++;
    }
    if (p == NULL || p->next == NULL)
        return false;
    q = p->next;  //令q指向被删除的结点
//e=q->data;    //用e返回元素的值
    if (q->next) {
        p->next = q->next;
    }//将*q结点从链表中断开
    free(q);
    return true;
}

bool deleteIndex(List list, int index) {
    if (index < 1) {
        return false;
    }
    if (index == 1) {
        Node s = malloc(sizeof(struct node));
        s = list;
        list = s->next;
        free(s);
        return true;
    } else {
        // TODO 按位查找 查找到的结点赋值给p 此方法可以抽出来 上面的插入也用到了
        Node p = list;
        int j = 0;
        while (index != j) {
            p = p->next;
            j++;
        }
        if (!p) {
            return false;
        }

        return DeleteNextLNode(p);

//        Node p = list;
//        int j = 0;    //计数
//        while (p && j < index - 1) {
//            p = p->next;
//            j++;
//        }
//        if (!p) {    // i值不合法：超过表长度
//            return false;
//        }
//        return DeleteNextLNode(p);
    }


}

// 后插操作：在p结点后插入数据e
bool InsertNextNode(Node p, int e) {
    if (p == NULL) {
        return false;
    }
    Node s = malloc(sizeof(Node));
    s->next = p->next;
    s->data = e;
    p->next = s;
    return true;
}

bool DeleteNextLNode(Node p) {
    if (p == NULL || p->next == NULL) { // p结点是最后一个
        return false;
    }
    Node s = malloc(sizeof(Node));
    s = p->next;
    p->next = s->next;
    free(s);
    return true;
}

void printList(List list) {
    while (list) {
        printf("%d->", list->data);
//        printf("\n");
//        printf("OX%p -> ", list);

//        printf("*list 指针（地址）的值为：OX%p\n",*list);

        list = list->next;
    }
}
Node findNode(List *list,Element data) {
    assert(list);
    Node pre = *list;
    Node cur = pre->next;
    if (NULL == pre) {
        return NULL;
    } else {
        while (cur->data != data && cur->next != NULL) {
            pre = cur;
            cur = pre->next;
        }
        if (NULL == cur->next) {
            return NULL;
        }
    }
}
void deleteData(List *list, Element data) {
    assert(list);
    Node pre = *list;
    Node cur = pre->next;

    Node p = findNode(list,data);

    pre->next = cur->next;
    free(cur);
    cur = NULL;
    /*
    Node pre = *list;
    Node cur = pre->next;
    if (NULL == pre){
        return;
    } else{
        while (cur->data != data && cur->next != NULL){
            pre = cur;
            cur = pre->next;
        }
        if (NULL== cur->next){
            return;
        } else{
            pre->next = cur->next;
            free(cur);
            cur = NULL;
        }
    }
    */
}

void deleteData2(List *list, Element data) {
    assert(list);
    Node pre = *list;
    Node cur = pre->next;
    if (NULL == pre) {
        return;
    } else {
        while (cur->data != data && cur->next != NULL) {
            pre = cur;
            cur = pre->next;
        }
        if (NULL == cur->next) {
            return;
        } else {
            pre->next = cur->next;
            free(cur);
            cur = NULL;
        }
    }
    /*
    Node head = list;
    Node pos,tag;
    pos = Find(list,data);

    if (NULL == *list || NULL == pos){
        return;
    }

    if (pos == *list){
        (*list) = pos->next;
        free(pos);
    } else{
        while (tag->next != pos){
            tag = tag->next;
        }
        tag->next = pos->next;
        free(pos);
    }
    */
}

void deleteAllData(List *list, Element data) {
    assert(list);
    Node pre,cur;
    while (NULL != Find(list,data)){
        pre = *list;
        cur = pre->next;
        if (NULL == *list){
            return;
        }
        if (data == pre->data){
            *list = cur;
            free(pre);
        } else {
            while (cur->data != data){
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            free(cur);
        }
    }
}
