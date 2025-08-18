#ifndef __Head_h__
#define __Head_h__
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int datatype;
enum{
	FALSE = -1,
	SUCCESS 
 
};
 
//定义节点的结构体
typedef struct Node{
 
	//数据域
	union{
		int data; //普通节点的数据元素
		int len; //头结点的链表长度
	};
 
	//指针域：存下一个节点的数据域
	struct Node *next;
	//存储上一个节点的指针
	struct Node *prev;
 
}*doubleLink;
 
doubleLink create_node(int);
int insert_head (doubleLink, datatype);
int print(doubleLink);
int printReverse(doubleLink);
int append(doubleLink, datatype);
int delete_rear(doubleLink);
int delete_head(doubleLink);
int insert_mid(doubleLink, int, datatype);
int delete_mid(doubleLink, int);
int edit(doubleLink, int, datatype);
int findValue(doubleLink,int);
int indexof(doubleLink, datatype);
int editKey(doubleLink, datatype, datatype);
int delete_key(doubleLink, datatype);
//int reverse(doubleLink);
int bubble(doubleLink);
int reverseFind(doubleLink, int);
int freeLinks(doubleLink);
int selection(doubleLink);
 
#endif
