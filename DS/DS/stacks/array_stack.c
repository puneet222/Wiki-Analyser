#include<stdio.h>
#include<malloc.h>

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

int isEmpty(struct arrayStack *S)
{
	return (S -> top == -1) ;
}

int isFull(struct arrayStack *S)
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

int main()
{
	struct arrayStack *S = createStack(3) ;
	//now we have a stack of size 3 ;
	int o , q =1;
	while(q)
	{
		printf("Enter 1 to Push Element\nEnter 2 to Pop an Element\nEnter 3 to EXIT ---> ");
		scanf("%d" , &o);
		switch(o)
		{
			case 1 :
			{
				int data ;
				printf("Enter the data : ") ;
				scanf("%d" , &data) ;
				push(S,data) ;
				break ;
			}
			case 2 :
			{
				int d = pop(S) ;
				if(d != 0)
				{
					printf("Popped Element is : %d\n", d);
				}
				break ;
			}
			case 3 :
			{
				q = 0 ;
			}
		}
	}
}