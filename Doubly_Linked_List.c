#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

void traversalOfDoublyLinkedList(struct Node *head,struct Node *fourth)
{
	struct Node *p=head;
	while(p != NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
	printf("NULL \n");
	struct Node *q=fourth;
	while(q !=NULL)
	{
		printf("%d->",q->data);
		q=q->prev;
	}
	printf("NULL");
	
}

int main()
{
	struct Node * head=(struct Node *)malloc(sizeof(struct Node));
	struct Node * second=(struct Node *)malloc(sizeof(struct Node));
	struct Node * third=(struct Node *)malloc(sizeof(struct Node));
	struct Node * fourth=(struct Node *)malloc(sizeof(struct Node));

	head->data=10;
	head->prev=NULL;
	head->next=second;
	
	second->prev=head;
	second->data=20;
	second->next=third;
	
	third->prev=second;
	third->data=30;
	third->next=fourth;
	
	fourth->prev=third;
	fourth->data=40;
	fourth->next=NULL;
	
	traversalOfDoublyLinkedList(head,fourth);
	
	return 0;
}
