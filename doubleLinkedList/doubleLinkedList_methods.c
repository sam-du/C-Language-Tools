#include "head.h"
 
//1.创建头节点
//flag ==1 给头结点初始化
//flag == 0 给普通节点初始化
doubleLink create_node(int flag){
 
	doubleLink s = (doubleLink)malloc(sizeof(struct Node));
	if(s == NULL){
		return NULL;
	}
	//内存申请成功
	
	if(flag == 1){ //头结点
		s->len = 0;
	}
	else if (flag == 0){ //普通节点
		s ->data = 0;
	}
	//初始化指针域 
	//成为循环节点
	s->next = NULL;
	s->prev = NULL;
 
	//返回新节点
	return s;
 
 
}
 
 
 
//2.链表头插
//判断头结点是否存在，创建一个新的节点， 连接，链表长度+1
//参数：插入的值，头结点，
//返回值：成功返回0，失败返回-1
//
int insert_head (doubleLink head, datatype element){
	//判断头结点是否存在
	if(head == NULL){
		return FALSE;
	}
 
	//头插入
	
	//创建一个新的节点
	doubleLink s = create_node(0);
	if(s == NULL){
		return FALSE;
	}
	
	//节点创建成功
	s->data = element; //对新节点的数据赋值
 
	//插入新节点
	s->next = head->next; 
	s->prev = head;
	if(head->next != NULL){
		head->next->prev = s;
	}
	head->next = s;
 
	//链表长度自增
	head -> len++;
	return SUCCESS;
}
 
//3. 链表的遍历，打印
 
int print(doubleLink head){
	if(head == NULL){
		return FALSE;
	}
	doubleLink ptr = head -> next; //保留头结点的地址
 
	while(ptr != NULL){
		printf("%d ", ptr -> data);
		ptr = ptr -> next;
	}
	putchar(10);
	return SUCCESS;
}
 
int printReverse(doubleLink head){
	if(head == NULL){
		return FALSE;
	}
	doubleLink ptr = head -> next; //保留头结点的地址
 
	while(ptr != NULL){
		ptr = ptr -> next;
	}
	ptr = ptr->prev;
	while(ptr != head){
		printf("%d ", ptr -> data);
		ptr = ptr -> prev;
	}
 
	putchar(10);
	return SUCCESS;
 
}
 
//4. 链表的尾插
int append (doubleLink head, datatype element){
	if(head == NULL){
		return FALSE;
	}
	//尾部插入
	//创建一个新的节点
	doubleLink last = create_node(0);
	last->data = element;
	if(last == NULL){
		return FALSE;
	}
	doubleLink  p = head;
	while(p-> next != NULL){
		p = p->next;
	}
 
	//在p 的后面添加节点
	p->next = last;
	last->prev = p;
	head ->len ++;
	return SUCCESS;
}
 
//5. 链表的尾删
int delete_rear(doubleLink head){
	//判断头结点是否为NULL
	//判断链表中至少有一个节点
	if(head == NULL || head->next == NULL){
		return FALSE;
	}
	doubleLink ptr = head; 
	while(ptr->next->next != NULL){
		ptr = ptr -> next;
	}
	free(ptr->next);
	ptr->next = NULL; 
	head->len --;
	return SUCCESS;
}
 
//6. 链表的头删
int delete_head(doubleLink head){
	if(head == NULL || head-> next == NULL){
		return FALSE;
	}
	
	//声明del 这样之后可以释放空间，避免空间浪费
	doubleLink del = head->next;
	//将头节点的next 指向 head->next->next
	head->next = del->next; 
	if(del->next != NULL){
		del->next->prev = head;
	}
	free(del);
	del = NULL;
	head->len--;
	return SUCCESS;
}
 
 
//7. 单量表按位置插入
//
 
int insert_mid(doubleLink head, int index, datatype element){
	if(head == NULL || index < 1 || index > head->len+1){
		printf("Insertion unavailble\n");
		return FALSE;
	}
	//创建一个新的节点
	doubleLink mid = create_node(0);
	mid->data = element;
	if(mid == NULL || index <= 0 || index > head->len+1){
		return FALSE;
	}
 
	//按位置插入
	doubleLink ptr = head;
	for (int i = 0 ; i < index-1; i++)
	{
		ptr = ptr->next;
	}
	//插入的节点等于下一个节点
	mid->next = ptr->next; 
	mid->prev = ptr;
	//上一个节点等于插入的节点
	if(ptr-> next != NULL){
		ptr ->next ->prev = mid;
	}
	ptr->next = mid;
	head ->len ++;
	return SUCCESS;
}
//===============================
//8. 单项链表按位置删除
int delete_mid(doubleLink head, int index){
	if(head == NULL || index <= 0 || index > head->len+1 ){
		return FALSE;
	}
	//声明指针用来遍历节点
	
	doubleLink mid = head; 
	//需要遍历到要删除的前一个节点
	for (int i = 0; i < index-1 ; i++)
	{
		mid = mid->next;
	}
 
	doubleLink del = mid->next; //要删除的节点
	mid->next = del->next; //连接后面一个节点
	if(del->next != NULL){
		del->next->prev = mid;
	}
	free(del);   //删除节点
	del = NULL;
	head->len--;
	return SUCCESS;
}
 
 
//9. 按位置修改 ==========================
int edit(doubleLink head, int index, datatype element){
	if(head == NULL || index <= 0 || index > head->len){
		printf("edit unavailble\n");
		return FALSE;
	}
	doubleLink mid = head;
	for (int i = 0 ; i < index; i++)
	{
		mid = mid -> next; 
	}
	mid->data=element; 
	return SUCCESS;
}
 
//10.按位查找
int findValue(doubleLink head, int index){
	if(head == NULL || index <= 0 || index > head->len){
		printf("find value not available \n");
		return FALSE;
	} 
	doubleLink mid = head; 
	for (int i = 0 ; i < index; i++)
	{
		mid = mid->next;
	}
 
	printf("%d\n", mid->data);
	return SUCCESS;
}
 
//11.按元素查找
//成功返回下标
int indexof(doubleLink head, datatype key){
	if(head == NULL ||head-> len == 0){
		return FALSE;
	}
	int index = 1;
	//需要指针遍历
	doubleLink ptr = head->next;
	while(ptr != NULL){
		if(ptr->data == key){
			return index;
		}
		index++; 
		ptr = ptr->next;
	}
	printf("Key not found");
	return FALSE;
 
}
 
	//12.按元素修改
int editKey(doubleLink head, datatype key, datatype new){
	if(head == NULL || head->len == 0 || indexof(head, key) == -1)
	{
		printf("Key not found\n");
		return FALSE;
	}
	int index = indexof(head, key);
	doubleLink insert = head;
	for (int i = 0 ; i < index; i++)
	{
		insert = insert->next;
	}
	insert->data = new; 
	return SUCCESS;
	
}
 
	//13.按元素删除
int delete_key (doubleLink head, datatype key){
	if(head == NULL || head->len == 0|| indexof(head,key)== -1){
		printf("key not found\n");
		return FALSE;
	}
	int index = indexof(head, key);
	doubleLink mid = head;
	for (int i = 0 ; i < index -1; i++)
	{
		mid = mid->next;
	}
	doubleLink del = mid->next; 
	mid -> next = del -> next; 
	if(del->next != NULL){
	del->next->prev = mid;
	}
	free(del);
	del = NULL; 
	head->len--;
	return SUCCESS;
}
 
 
//15. 单链表的排序
int bubble(doubleLink head){
	if(head == NULL || head->len <= 1){
		printf("Order does not apply\n");
		return FALSE;
	}
	for (int i = 1 ; i < head->len; i++)
	{
		doubleLink ptr = head->next;
		for (int j = 0; j < head->len -i; j++)
		{
			if(ptr->data > ptr -> next->data){
				datatype temp = ptr->data;
				ptr->data = ptr->next ->data ;
				ptr->next->data  = temp;
 
			}
			ptr = ptr->next;
		}
	}
	return SUCCESS;
	
}
 
int selection (doubleLink head){
	if(head == NULL || head->len <=1){
		return FALSE;
	}
	for (doubleLink i = head->next ; i->next != NULL; i = i->next)
	{
		doubleLink min = i;
		for (doubleLink j = i->next  ; j!= NULL; j = j->next)
		{
			if(min->data > j->data){
				min = j;
			}
		}
		datatype temp = min->data; 
		min -> data = i->data;
		i->data = temp;
	}
	return SUCCESS;
 
 
 
}
 
 
//16. 单链表找到倒数第n 个节点
int reverseFind(doubleLink head, int index){
	if(head == NULL || head -> len <= 1 || index <= 0 || index >= head->len){
		printf("input invalid\n");
		return FALSE;
	}
	doubleLink ptr = head; 
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	for (int i = 1 ; i < index; i++)
	{
		ptr = ptr->prev;
	}
	printf("%d\n", ptr->data);
	return SUCCESS;
}
 
//17. 释放内存空间
int freeLinks(doubleLink head){
	int len = head->len;
	for (int i = 0 ; i < len; i++)
	{
		delete_head(head);
	}
	free(head);
	head = NULL;
 
}
