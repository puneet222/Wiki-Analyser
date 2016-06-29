#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct stack
{
	int top ;
	int capacity ;
	int *array ;
} ;

struct stack *createStack(int size)
{
	struct stack *S = malloc(sizeof(struct stack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(S -> capacity * sizeof(int)) ;
	return S  ;
}

int isFull(struct stack *S)
{
	return S -> top == S -> capacity - 1 ;
}

int isEmpty(struct stack *S)
{
	return S -> top == -1 ;
}

void push(struct stack *S  , int data)
{
	if(isFull(S))
	{
		printf("Stack Overflow\n");
		return ;
	}
	S -> array[++S -> top] = data ;
}

int pop(struct stack *S)
{
	if(isEmpty(S))
	{
		return INT_MIN;
	}
	int d = S -> array[S -> top] ;
	S -> top-- ;
	return d ;
}
void display(struct stack *S)
{
	if(isEmpty(S))
		printf("Stack is Empty\n");
	else
	{
		int ind = S -> top ;
		while(ind != -1)
		{
			printf("elements of stack are : %d\n", S -> array[ind]);
			ind-- ;
		}
	}
}

int main()
{
	int arr[10] , n , i;
	printf("Enter number of elements : ");
	scanf("%d" , &n) ;
	struct stack *S = createStack(n) ;
	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the element number %d\n", i + 1 );
		scanf("%d" , &arr[i]) ;
	}
	

	for (i = 0; i < n; i++)
	{
		display(S) ;
		printf("Number of elements is stack are : %d\n" , S -> top + 1);
		printf("value of i is : %d\n", i );
		if(isEmpty(S))
		{
			push(S , i) ;
					}
		else
		{
			if(arr[i] < arr[S -> array[S -> top]])
			{
				printf("I'm in else if\n");
				push(S , i) ;
			}
			else
			{
				while(!isEmpty(S) && arr[i] > arr[S -> array[S -> top]])
				{
					int index = pop(S) ;
					arr[index] = arr[i] ;
				}
				push(S , i) ;
			}
		}
	}

	for(i = 0 ; i < n ; i++)
	{
		printf(" %d  ", arr[i]);
	}
}