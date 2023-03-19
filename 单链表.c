#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* createlist()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}
//�����ڵ�
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
//��ӡ�ڵ�
void printlist(struct Node* headNode)
{
	struct Node* pmove = headNode->next;
	while (pmove)
	{
		printf("%d", pmove->data);
		pmove = pmove->next;
	}
	printf("\n");
}
//����ڵ�
void insertNodeByhead(struct Node* headNode,int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;

}
//ָ��λ��ɾ��
void deleteNodeByAppoint(struct Node* headNode, int posdata)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
	{
		printf("����Ϊ��");
	}
	else {
		while (posNode->data != posdata)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode == NULL) {
				printf("�޷�ɾ��\n");
				break;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}
}
int main()
{
	int first = 0;
	int second = 0;
	int third = 0;
	int random = 0;
	scanf_s("%d%d%d", &first, &second, &third);
	struct Node* list = createlist();
	insertNodeByhead(list, first);
	insertNodeByhead(list, second);
	insertNodeByhead(list, third);
	printlist(list);
	//printf("\n");
	scanf_s("%d", &random);
	deleteNodeByAppoint(list, random);
	printlist(list);
	return 0;
}




