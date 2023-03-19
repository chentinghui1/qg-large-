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
	struct Node* firstNode;  //��һ���ڵ�
	struct Node* lastNode;  //���һ���ڵ�
};
struct List* createList()
{
	struct List* list = (struct List*)malloc(sizeof(struct List));  //�����ڴ�,ע�⣺list����û��size��
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
//���С,sizeΪ����Ͳ���
/*int listsize(struct List* list)
{
	return list->size;
}
//�ж��Ƿ�Ϊ��
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
		printf("��");
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
