#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct list
{
	int data ;
	struct list *next ;
};

struct queue
{
	struct list *s1 , *s2 ;
};

struct queue *createQueue()
{
	struct queue *Q = malloc(sizeof(struct queue)) ;
	Q -> s1 = NULL ;
	Q -> s2 = NULL ;
}

void push(struct list **head , int data)
{
	struct list *newNode = malloc(sizeof(struct list)) ;
	newNode -> data = data ;
	newNode -> next = NULL ;
	if(*head == NULL)
	{
		*head = newNode ;
		return ;
	}
	newNode -> next = *head ;
	*head = newNode ;
}

void display(struct list *head)
{
	if(head == NULL)
	{
		printf("Stack is Empty\n");
	}
	while(head != NULL)
	{
		printf(" %d ", head -> data );
		head = head -> next ;
	}
	printf("\n");
}

int pop(struct list **head)
{
	if(*head == NULL)
	{
		printf("Stack is empty\n");
		return INT_MIN ;
	}
	struct list *ptr = *head ;
	*head = ptr -> next ;
	ptr -> next = NULL ;
	return ptr -> data ;
}

int top(struct list *head)
{
	if(head == NULL)
	{
		printf("Stack is Empty\n");
		return INT_MIN ;
	}
	return head -> data ;
}

void deleteStack(struct list **head)
{
	if(*head == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	struct list *temp , *p ;
	p = *head ;
	while(p -> next != NULL)
	{
		temp = p -> next;
		p -> next = temp -> next ;
		free(temp);
	}
	free(p);
}


void EnQueue(struct queue *Q , int data) 
{
	push(&Q -> s1 , data) ;
}

int DeQueue(struct queue *Q)
{
	if(Q -> s1 == NULL && Q -> s2 == NULL)
	{
		printf("Queue is Empty\n");
		return INT_MIN ;
	}
	if(Q -> s2 == NULL)
	{
		while(Q -> s1 != NULL)
		{
			push(&Q -> s2 , pop(&Q -> s1)) ;
		}
		return pop(&Q -> s2) ;
	}
	return pop(&Q -> s2) ;
}

int main()
{
	struct queue *Q = createQueue() ;
	int i ;
	for(i = 0 ; i < 5; i++)
		EnQueue(Q , i+1);

	for(i = 0 ; i < 6 ; i++)
	{
		int data = DeQueue(Q);
		printf("DeQueued data is %d\n", data);
	}

	EnQueue(Q , 10) ;
	int data = DeQueue(Q);
	printf("DeQueued data is %d\n", data);
}