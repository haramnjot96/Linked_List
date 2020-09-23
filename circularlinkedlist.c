#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

void traversalOfList(struct Node *head)
{
	struct Node *ptr=head;
	do
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
	while(ptr != head);
}

struct Node * insertionInCircularList(struct Node *head,int data)
{
	struct Node *ptr=(struct Node *)malloc (sizeof(struct Node));
	ptr->data=data;
	
	struct Node *p=head->next;
	while(p->next != head)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=head;
	head=ptr;
	return head;
}
int main()
{
	struct Node *head=(struct Node *)malloc(sizeof(struct Node));
	struct Node *first=(struct Node *)malloc(sizeof(struct Node));
	struct Node *second=(struct Node *)malloc(sizeof(struct Node));
	struct Node *third=(struct Node *)malloc(sizeof(struct Node));
	
	head->data=10;
	head->next=first;
	
	first->data=20;
	first->next=second;
	
	second->data=30;
	second->next=third;
	
	third->data=40;
	third->next=head;
	
	traversalOfList(head);
	printf("\n");
	
	head=insertionInCircularList(head,50);
	traversalOfList(head);
	
	return 0;
}
