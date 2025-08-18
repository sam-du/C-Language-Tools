#include "head.h"
int main(int argc, const char *argv[])
{
	//1. define a ordered list
	sqlist list = create_sqlist();
 
	//2. 顺序表尾部插入
	//
	datatype element;
	for (int i = 0 ; i < MAXSIZE; i++)
	{
		printf("please eneter an element>>>");
		scanf("%d", &element);
		insert_rear(list, element);
 
	}
	//3. 循环打印顺序表
	output(list);
 
	//4. 尾部删除
	delete_rear(list);
	delete_rear(list);
	output(list);
 
	//5.按下表查找
	
	int index1; 
	printf("Enter the index for search >>");
	scanf("%d", &index1);
	search(list, index1);
 
 
	//6. 按下表修改元素
	printf("Enter the index for edit >>");
	int index2; 
	scanf("%d", &index2);
	datatype element_edit;
	printf("Enter the element for edit>>");
	scanf("%d", &element_edit);
	edit(list, index2, element_edit);
	output(list);
 
	//7. 按下表添加元素
	int index3; 
	printf("Enter the index for adding >>");
	scanf("%d", &index3);
	printf("Enter the element for adding>>");
	scanf("%d", &element);
	add(list, index3, element);
	output(list);
 
 
	//8. 删除下标制定的元素
	int index4;
	printf("Enter the index for delete>>");
	scanf("%d", &index4);
	delete_index(list, index4);
	output(list);
 
 
	//9.按元素删除元素
	printf("Enter the element you want to delete>>");
	datatype element_delete; 
	scanf("%d", &element_delete);
	delete_element(list, element_delete);
	output(list);
 
	//10. 按元素查找下标
	printf("Enter the element you want to find\n");
	datatype element_find;
	scanf("%d", &element_find);
	int index5 = indexof(list, element_find);
	printf("index: %d\n", index5);
 
	//11.按元素修改
	printf("Enter the element in the ARR for edit>>");
	datatype old; 
	scanf("%d", &old);
	printf("Enter the new element to replace>>");
	datatype new;
	scanf("%d", &new);
	edit_element(list, old, new);
	output(list);
 
	//12. 按元素去重
	printf("Delete the repetitions:\n");
	delete_repeat(list);
	output(list);
 
 
	//13. 元素排序
	printf("List Bubble Sort: \n");
	bubbleSort(list);
	output(list);
 
	//14.释放顺序表
	freeList(list);
 
	return 0;
} 
