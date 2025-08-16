#include "head.h"
int main(int argc, const char *argv[])
{
	//1.创建头节点
	//
	doubleLink head = create_node(1);
	
	//2.链表头插
	datatype element1; 
	for (int i = 0 ; i < 7; i++)
	{
 
		printf("Enter element:");
		scanf("%d", &element1);
		insert_head(head, element1);
	}
 
	//3.打印链表
	print(head);
	//4.链表的尾插
	datatype element2;
	printf("Enter the element to insert at the end>>");
	scanf("%d", &element2);
	append(head, element2);
	print(head);
 
 
 
	//5. 链表的尾删
	printf("Delete the last element:\n");
	delete_rear(head);
	print(head);
 
 
	//6. 链表的头删
	printf("Delete the first element:\n");
	delete_head(head);
	print(head);
 
 
	//7. 单量表按位置插入
	printf("Enter the index for inserting>> ");
	int index1;
	scanf("%d", &index1);
	printf("Enter the element for inserting>>");
	datatype element3; 
	scanf("%d", &element3);
	insert_mid(head, index1, element3);
	print(head);
	
	//8. 单项链表按位置删除
	printf("Enter the index for deleting>> ");
	int index2;
	scanf("%d", &index2);
	delete_mid(head, index2);
	print(head);
 
	//9.单链表按位置修改
	printf("Enter the index for editing>>");
	int index3; 
	scanf("%d", &index3);
	datatype element4; 
	printf("Enter the new element>>");
	scanf("%d", &element4);
	edit(head, index3, element4);
	print(head);
 
 
	//10. 按位置查找
	printf("Enter the index to find the element>>");
	int index4; 
	scanf("%d", &index4);
	printf("The value is >>");
	findValue(head, index4);
 
 
	//11. 按元素查找
	printf("Enter the key>>");
	datatype key1;
	scanf("%d", &key1);
	int n = indexof(head, key1);
	printf("Index of the key is %d\n",n);
 
	//12.按元素修改
	printf("Enter the key for edit>>");
	datatype key2; 
	scanf("%d", &key2);
	printf("Enter the new element for replacement>>");
	datatype element5; 
	scanf("%d", &element5);
	editKey(head, key2, element5);
	print(head);
 
 
	//13.按元素删除
	printf("Enter the key for deleting\n");
	datatype key3; 
	scanf("%d", &key3);
	delete_key(head, key3);
	print(head);
 
	//14.链表逆置
	//printf("Reverse the Linked List\n");
	//reverse(head);
	//print(head);
 
	//15. 单链表的排序
	printf("Bubble Sort\n");
	bubble(head);
	print(head);
 
	//选择排序
	printf("selection sort \n");
	//reverse(head);
	selection(head);
	print(head);
	//16. 单链表找到倒数第n 个节点
	int index5; 
	printf("Enter the index in reverse>> ");
	scanf("%d", &index5);
	printf("The element in reverse order is ");
	reverseFind(head, index5);
 
	//释放内存
	freeLinks(head);
 
 
 
	return 0;
}
