#include<stdio.h>
#include<malloc.h>
#include<limits.h>

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

void resizeQueue(struct queue *Q)
{
	int size = Q -> capacity ;
	Q -> capacity *= 2 ;
	Q -> array = realloc(Q -> array , Q -> capacity) ;

	if(Q -> front > Q -> rear)
	{
		int i ;
		for(i = 0 ; i < Q -> front ; i++)
		{
			Q -> array[i + size] = Q -> array[i] ;
		}
		Q -> rear = Q -> rear + size ;
	}
}

void EnQueue(struct queue *Q , int data)
{
	if(isFull(Q))
	{
		resizeQueue(Q) ;
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
	int i = 1, n ;
	struct queue *Q = createQueue(1) ;
	int o ;
	while(i)
	{
		printf("Enter 1 to EnQueue\nEnter 2 to DeQueue\nEnter 3 to get the size of the queue\nEnter 4 to exit\n------------------->");
		scanf("%d" , &o) ;
		switch(o)
		{
			case 1 :
			{
				int data ; 
				printf("Enter the data : ");
				scanf("%d" , &data) ;
				EnQueue(Q , data) ;
				break ;
			}
			case 2 :
			{
				int data = DeQueue(Q) ;
				if(data != INT_MIN)
				{
					printf("Data i.e. DeQueued is : %d \n",data );
				}
				else
				{
					printf("Queue is Empty\n");
				}
				break ;
			}
			case 3 :
			{
				int size = getQSize(Q) ;
				printf("Size of the queue is : %d\n", size);
				break ;
			}
			case 4 :
			{
				i = 0 ;
			}
		}
	}
}