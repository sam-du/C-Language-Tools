#ifndef __HEAD_H__
 
#define __HEAD_H__
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
enum type{
	FALSE = -1,  //if false return FALSE
	SUCCESS
 
};
 
 
//define the max length of array
#define MAXSIZE 7
 
//nickname for datatypes 
typedef int datatype; 
 
//define the struct 
//elements and length 
typedef struct sqlist{
	//elements 
	datatype data[MAXSIZE];
	//length
	int len;
}*sqlist;
//sqlist is a type of struct Sqlist*
 
sqlist create_sqlist();
int insert_rear(sqlist, datatype);
int output(sqlist);
int delete_rear(sqlist);
int search(sqlist, int);
int edit(sqlist, int, datatype);
int add(sqlist, int, datatype);
int delete_index(sqlist, int);
int delete_element(sqlist, datatype);
int indexof(sqlist, datatype);
int edit_element(sqlist, datatype,datatype);
int delete_repeat(sqlist);
int bubbleSort(sqlist);
int freeList(sqlist);
#endif
