#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct arrayStack
{
	int top ; 
	int capacity ;
	int *array ;
};

struct arrayStack *createStack(int size)
{
	struct arrayStack *S = malloc(sizeof(struct arrayStack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(sizeof(int)*S->capacity) ;
	return S ;
}

int isStackEmpty(struct arrayStack *S)
{
	return (S -> top == -1) ;
}

int isStackFull(struct arrayStack *S)
{
	return (S -> top == (S -> capacity)-1) ;
}

int pop(struct arrayStack *S)
{
	if(isEmpty(S))
	{
		printf("Array is Empty\n");
		return 0;
	} 
	else
	{
		int data = S->array[S->top] ;
		S-> top-- ;
		return data ;
	}
}

void push(struct arrayStack *S, int data)
{
	if(isFull(S))
	{
		printf("StackOverflow\n");
		return ;
	}
	else
	{
		S->array[++S->top] = data ;
		printf("Inserted Successfully\n");
	}
}

struct queue
{
	int front , rear ;
	int capacity ;
	int *array ;
};

struct queue *createQueue(int size)
{
	struct queue *Q = malloc(sizeof(struct queue)) ;
	if(!Q)
	{
		printf("creation of queue is not possible\n");
		return NULL ;
	}
	Q -> front = -1 ;
	Q -> rear = -1 ;
	Q -> capacity = size ;
	Q -> array = malloc(Q -> capacity * sizeof(int)) ;
	if(!Q -> array)
	{
		printf("creation of array of queue is not possible\n");
		return NULL ;
	}
	return Q ;
}

int isEmpty(struct queue *Q)
{
	return Q -> front == -1 ;
}

int isFull(struct queue *Q)
{
	return ((Q -> rear + 1) % Q -> capacity == Q -> front) ;
}

int getQSize(struct queue *Q)
{
	return (Q -> capacity - Q -> front + Q -> rear + 1) % Q -> capacity ;
}

void EnQueue(struct queue *Q , int data)
{
	if(isFull(Q))
	{
		printf("Queue Overflow\n") ;
		return ;
	}
	Q -> rear = (Q -> rear + 1)%Q->capacity ;
	Q -> array[Q -> rear] = data ;
	if(Q -> front == -1)
	{
		Q -> front = Q -> rear ;
	} 
}

int DeQueue(struct queue *Q)
{
	if(isEmpty(Q))
	{
		return INT_MIN ;
	}
	else
	{
		int d = Q -> array[Q -> front] ;
		
		if(Q -> front == Q -> rear) // one element in the queue
			Q -> front = Q -> rear = -1 ;
		else
			Q -> front = (Q -> front + 1) % Q -> capacity ;

		return d ;		
	}
	
}

int main()
{
	struct queue *Q = createQueue(11) ;
	int i , k;
	for(i = 0 ; i < 10 ; i++)
		EnQueue(Q , (i+1)*10) ;

	printf("Enter the value till the elements of queue is reversed : ");
	scanf("%d" , &k) ;

	struct arrayStack *S = createStack(k) ;
	for(i = 0 ; i < k ; i++)
	{
		push(S , DeQueue(Q)) ;
	}

	while(!isStackEmpty(S))
	{
		EnQueue(Q , pop(S)) ;
	}



	int size = getQSize(Q) ;
	
	for (i = 0; i < size - k; i++)
	{
		int t = DeQueue(Q) ;
		EnQueue(Q , t) ;
	}

		while(!isEmpty(Q))
	{
		int d = DeQueue(Q) ;
		printf(" %d  ", d);
	}
}