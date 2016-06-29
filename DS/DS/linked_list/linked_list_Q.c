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
	struct list *front ;
	struct list *rear ;
};

struct queue *createQueue()
{
	struct queue *Q = malloc(sizeof(struct queue)) ;
	Q -> front = NULL ;
	Q -> rear = NULL ;
}

void EnQueue(struct queue *Q , int data)
{
	struct list *newNode = malloc(sizeof(struct list)) ;
	newNode -> next = NULL ;
	newNode -> data = data ;
	if(Q -> rear == NULL)
	{
		Q -> front = newNode ;
		Q -> rear = newNode ;
	}
	else
	{
		Q -> rear -> next = newNode ;
		Q -> rear = newNode ;
	}
}

int DeQueue(struct queue *Q)
{
	if(Q -> front == NULL)
	{
		printf("Queue is Empty\n");
		return INT_MIN ;
	}
	struct list *ptr ;
	ptr = Q -> front -> next ;
	int data = Q -> front -> data ;
	Q -> front -> next = NULL ;
	free(Q -> front) ;
	Q -> front = ptr ;
	return data ;
}

void display(struct queue *Q)
{
	struct list *ptr = Q -> front ;
	while(ptr != NULL)
	{
		printf(" %d ", ptr -> data);
		ptr = ptr -> next ;
	}
}

int main()
{
	struct queue *Q = createQueue() ;
	int i ;
	for(i = 1 ; i < 8 ; i++)
		EnQueue(Q , i) ;

	display(Q) ;

	int d = DeQueue(Q) ;

	printf("DeQueued data is %d\n", d);
}