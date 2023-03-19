#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* front;
	struct Node* tail;
};
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->front = newNode->tail = NULL;
	return newNode;
}
struct List
{
	int size;
	struct Node* firstNode;  //第一个节点
	struct Node* lastNode;  //最后一个节点
};
struct List* createList()
{
	struct List* list = (struct List*)malloc(sizeof(struct List));  //申请内存,注意：list空是没有size的
	list->size = 0;
	list->firstNode = list->lastNode = NULL;
	return list;
}
void insertNodeByhead(struct List* list, int data)
{
	struct Node* newNode = createNode(data);
	if (list->firstNode == NULL)
	{
		list->firstNode = newNode;
		list->lastNode = newNode;
		list->firstNode = newNode;
	}
	else
	{
		list->firstNode->front = newNode;
		newNode->tail = list->firstNode;
		list->firstNode = newNode;
	}
	list->size++;
}
//求大小,size为万金油参数
/*int listsize(struct List* list)
{
	return list->size;
}
//判断是否为空
int emptyList(struct List* list)
{
	if (list->size == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}*/
void printList(struct List* list)
{
	if (list->size == 0)
	{
		printf("空");
	}
	else
	{
		struct Node* pMove = list->firstNode;
		while (pMove)
		{
			printf("%d", pMove->data);
			pMove = pMove->tail;
		}
	}
}
int main()
{
	int first = 0;
	int second = 0;
	int third = 0;
	scanf_s("%d%d%d", &first, &second, &third);
	struct List* list = createList();
	insertNodeByhead(list, first);
	insertNodeByhead(list, second);
	insertNodeByhead(list, third);
	printList(list);
	system("pause");
	return 0;
}
