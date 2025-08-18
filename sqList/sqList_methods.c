#include "head.h"
 
/*
 * function:
 * @param[ in]
 * @param[out]
 * @return
*/
sqlist create_sqlist(){
	sqlist list = (sqlist)malloc(sizeof(struct sqlist));
	if(NULL== list){
		return NULL;
	}
	//malloc success 
	
	//clean the elements to 0
	bzero(list -> data, sizeof(list -> data));
	
	//set the len as zero
	list -> len = 0;
 
	//return the list 
	return list;
 
}
 
/*
 * function: 数据表尾部插入
 * @param[ in] list, 插入的值element
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int insert_rear(sqlist list, datatype element){
	//1. 判断是否为满
	//2. 判断顺序表是否为空
	if(NULL == list || list -> len == MAXSIZE){
		printf("Sqlist full\n");
		return FALSE;
	}
	//3.在顺序表的尾部插入
	list->data[list->len] = element;
	//插入后长度自增
	list->len++;
 
	return SUCCESS;
}
 
/*
 * function: 循环打印顺序表
 * @param[ in] 
 * @param[out] 顺序表
 * @return 成功为0，失败为-1
*/
 
int output (sqlist list){
	//判断顺序表是否为空，是否为NULL
	if(list == NULL || list->len == 0){
		printf("sqlist empty\n");
		return FALSE;
	}
 
	//循环输出
	for (int i = 0; i < list->len; i++)
	{
		printf("%d ", list->data[i]);
	}
	putchar(10);
	return SUCCESS;
 
}
/*
 * function: 数据表尾部删除(删除len -1 对应的值)
 * @param[ in] 顺序表
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int delete_rear (sqlist list){
	if(list == NULL || list->len ==0 ){
		printf("sqlist empty\n");
		return FALSE;
	}
 
	//不需要置0，会被覆盖的
	list->len--;
	return SUCCESS;
 
}
 
/*
 * function: 按下表查找
 * @param[ in] 顺序表  下标
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int search (sqlist list, int index){
//顺序表没有元素，顺序表List = NULL, 下标超出范围
	if(list == NULL || list->len == 0 || index < 0 || index >= list -> len){
		printf("Error \n");
		return FALSE;
	}
	printf("list[%d] = %d\n",index, list-> data[index]);
	return SUCCESS;
 
}
 
 
/*
 * function: 按下表修改元素
 * @param[ in] 顺序表  下标 元素
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int edit (sqlist list, int index, datatype element){
	//顺序表没有元素，是否为NULL, index 是否超出范围
	if(list == NULL || list->len == 0 || index < 0 || index >= list->len){
		printf("Edit Error");
		return FALSE;
	}
	list -> data[index] = element; 
	
	return SUCCESS;
} 
 
 
/*
 * function: 按下表添加元素
 * @param[ in] 顺序表  下标 元素
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int add (sqlist list, int index, datatype element){
	//下标超出范围,顺序表是否为NULL.是否满
	if(index < 0 || list->len == MAXSIZE || index > list->len){
		printf("Add Error \n");
		return FALSE;
	}
 
	//元素后移
	for (int i = list->len-1; i >= index ; i--)
	{
		list->data[i+1] = list->data[i];
	}
	list->len++;
	list->data[index] = element; 
	
	return SUCCESS;
}
 
/*
 * function: 按下表删除元素
 * @param[ in] 顺序表  下标
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int delete_index (sqlist list, int index){
	//顺序表没有元素，顺序表为NULL，index 超出范围
	if(list == NULL|| list->len == 0 || index <0 || index >= list->len){
		printf("Delete Error \n");
		return FALSE;
	}
	list->len--;
	for (int i = index ; i < list->len; i++)
	{
		list->data[i] = list->data[i+1];
	}
	return SUCCESS;
}
 
/*
 * function: 按元素删除元素
 * @param[ in] 顺序表  元素
 * @param[out] 
 * @return 成功为0，失败为-1
*/
int delete_element(sqlist list, datatype element){ 
	if(indexof(list,element) == -1){
		printf("Element DNE\n");
		return FALSE;
	}
	for (int i = 0 ; i < list->len ; i++)
	{
		if(list->data[i] == element){ 
			delete_index(list, i);
			return SUCCESS;
		}
	}
	printf("Element not found\n");
	return FALSE;
 
 
}
 
 
/*
 * function: 按元素查找下标
 * @param[ in] 顺序表  元素
 * @param[out] 
 * @return 成功为return index，失败为-1
*/
 
int indexof (sqlist list, datatype element){
	if(list == NULL || list -> len == 0){
		printf("Element not found \n");
		return FALSE;
	}
 
	for (int i = 0 ; i < list ->len ; i++)
	{
		if(list->data[i] == element){
			return i;
		}
	}
	return FALSE;
 
}
 
 
/*
 * function: 顺序表按元素修改
 * @param[ in] 顺序表 元素 新元素
 * @param[out] 
 * @return 成功为0，失败为-1
*/
int edit_element(sqlist list, datatype old, datatype new){
	if(list == NULL || list->len  == 0 || indexof(list, old) == -1){
		printf("Element DNE\n");
		return FALSE;
	}
	edit(list, indexof(list, old), new);
	return SUCCESS;
}
 
 
/*
 * function: 顺序表去重
 * @param[ in] 顺序表 
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int delete_repeat (sqlist list){
	for (int i = 0 ; i < list->len-1; i++)
	{
		for (int j = i+1; j < list->len; j++)
		{
			if(list->data[i] == list->data[j]){
				delete_index(list, j);
				j--;
			}
		}
	}
 
}
/*
 * function: 顺序排序
 * @param[ in] 顺序表 
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int bubbleSort (sqlist list){
	for (int i = 1; i < list->len ; i++)
	{
		for (int j = 0 ; j < list->len -i; j++)
		{
			if(list->data[j] > list->data[j+1]){
				datatype temp = list->data[j];
				list->data[j] = list->data[j+1];
				list->data[j+1] = temp;
			}
		}
	}
	return SUCCESS;
}
 
 
/*
 * function: 释放顺序表
 * @param[ in] 顺序表 
 * @param[out] 
 * @return 成功为0，失败为-1
*/
 
int freeList (sqlist list){
	if(list == NULL){
		printf("List already free\n");
		return FALSE;
	}
	free(list);
	return SUCCESS;
 
}
 
