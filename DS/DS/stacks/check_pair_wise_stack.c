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

int checkStackPairOrder(struct arrayStack *S)
{
	int flag = 1 ;
	struct queue *Q = createQueue(15) ;

	while(!isStackEmpty(S))
	{
		EnQueue(Q , pop(S)) ;
	}

		// 	while(!isEmpty(Q))
	// {
	// 	int d = DeQueue(Q) ;
	// 	printf(" %d ", d);
	// }

	while(!isEmpty(Q))
	{
		push(S , DeQueue(Q)) ;
	}

	// while(!isStackEmpty(S))
	// {
	// 	int d = pop(S) ;
	// 	printf(" %d  ", d);
	// }

	while(!isStackEmpty(S)) 
	{
		int a = pop(S) ;
		EnQueue(Q , a) ;
		if(!isStackEmpty(S))
		{
			int b = pop(S) ;
			EnQueue(Q , b) ;
			if(a - b != 1 || a - b != -1)
			{
				flag = 0 ;
				break ;
			}
		}
	}

	while(!isEmpty(Q))
	{
		push(S , DeQueue(Q)) ;
	}

	return flag ;
}

int main()
{
	int n , i;
	printf("Enter the size of the stack : \n");
	scanf("%d" , &n) ;
	struct arrayStack *S = createStack(n) ;
	int d ;
	for(i = 0 ;  i < n ; i++)
	{
		printf("Enter Element : \n");
		scanf("%d" , &d) ;
		push(S , d) ;
	}

	// for (i = 0; i < n; i++)
	// {
	// 	int d = pop(S) ;
	// 	printf(" %d ", d);
	// }

	if(checkStackPairOrder(S))
		printf("pairwise\n");
	else
		printf("not") ;

}