//
//  linkedList.c
//  linkedList
//
//  Created by 曾长欢 on 2022/11/4.
//

#include "linkedList.h"
#include <stdlib.h>     // 提供 malloc、realloc、free、exit 原型
#include <string.h>     // 提供 strstr 原型

void initList(LinkList head);

bool insertList(LinkList head,Element element,int index);

bool deleteList(LinkList head,int index);

Element *getList(LinkList head,int index);

int findList(LinkList head,Element element);

int length(LinkList list);

void printList(LinkList head);

