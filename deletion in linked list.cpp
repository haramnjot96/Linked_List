#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node * next;
};

void traversalLinkedList(struct Node *ptr)
{
	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr=ptr->next;
	}
}

struct Node * deletionAtHead(struct Node *head)
{
	struct Node * p=head;
	head=head->next;
	free(p);
	return head;
}

struct Node * deletionAtIndex(struct Node *head,int index)
{
	struct Node * p=head;
	struct Node *q=head->next;
	int i=0;
	for(i=0;i<index-1;i++)
	{
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}

struct Node * deletionAtLast(struct Node *head)
{
	struct Node *p=head;
	struct Node *q=head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	
	free(q);
	
	return head;	

}

struct Node * deletionByValue(struct Node *head,int value)
{
	struct Node *p=head;
	struct Node *q=head->next;
	
	while(q->next!=NULL && q->data!=value)
	{
		p=p->next;
		q=q->next;
	}
	if(q->data==value){
	
	p->next=q->next;
	
	free(q);
}
	return head;
	
	
}
int main()
{
	struct Node *head=(struct Node *)malloc(sizeof(struct Node));
	struct Node *first=(struct Node *)malloc(sizeof(struct Node));
	struct Node *second=(struct Node *)malloc (sizeof(struct Node));
	struct Node *third=(struct Node *)malloc(sizeof(struct Node));

	head->data=10;
	head->next=first;
	
	first->data=20;
	first->next=second;
	
	second->data=30;
	second->next=third;
	
	third->data=40;
	third->next=NULL;
	
	traversalLinkedList(head);
	
//	head=deletionAtHead(head);
//	head=deletionAtIndex(head,1);
//	head=deletionAtLast(head);
	head=deletionByValue(head,30);
	printf("NULL\n");
	traversalLinkedList(head);
	printf("NULL");		
	return 0;
}
