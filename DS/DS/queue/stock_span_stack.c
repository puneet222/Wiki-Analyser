#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct stack
{
	int top ;
	int capacity ;
	int *array ;
};

struct stack *createStack(int size)
{
	struct stack *S = malloc(sizeof(struct stack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(sizeof(S -> capacity * sizeof(int))) ;
	return S ;
}

int isEmpty(struct stack *S)
{
	return S -> top == -1 ;
}

int isFull(struct stack *S)
{
	return S -> top == S -> capacity - 1 ;
}

void push(struct stack *S , int data)
{
	if(isFull(S))
	{
		printf("Stack Overflow\n");
		return ;
	}
	else
	{
		S -> array[++S -> top] = data ;
	}
}

int pop(struct stack *S)
{
	if(isEmpty(S))
	{
		printf("Stack Underflow\n");
		return INT_MIN ;
	}
	int d = S -> array[S -> top] ;
	S -> top-- ;
	return d ;
}

int top(struct stack *S)
{
	if(isEmpty(S))
	{
		printf("Stack is empty\n");
		return INT_MIN ;
	}
	return S -> array[S -> top] ;
}

int main()
{

	int arr[10] , n , i , P;
	printf("Enter the number of days\n");
	scanf("%d" , &n) ;
	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the price for day %d : ", i + 1 );
		scanf("%d" , &arr[i]) ;
	}
	int Span[10] ;
	struct stack *S = createStack(n) ;


	for(i = 0 ; i < n ; i++)
	{
		while(!isEmpty(S) && arr[i] > arr[S -> top])
		{
			pop(S) ;
		}

		if(isEmpty(S))
			P = -1 ;
		else
			P = top(S) ;

		Span[i] = i - P ;

		push(S , i) ;
	}
	printf("Stock span is : \n");
	for(i = 0 ; i < n ; i++)
	{
		printf(" %d ", Span[i]);
	}
}