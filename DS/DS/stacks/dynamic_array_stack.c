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
		return INT_MIN;
	} 
	else
	{
		int data = S->array[S->top] ;
		S-> top-- ;
		return data ;
	}
}

void doubleStack(struct arrayStack *S)
{
	S -> capacity *= 2 ;
	S -> array = realloc(S -> array , S -> capacity) ;
	printf("capacity of array is  : %d\n" , S -> capacity);
}

void push(struct arrayStack *S, int data)
{
	if(isFull(S))
	{
		doubleStack(S) ;
	}

		S->array[++S->top] = data ;
		printf("Inserted Successfully\n");

}

int top(struct arrayStack *S)
{
	if(isEmpty(S))
	{
		printf("Stack is Empty\n");
		return INT_MIN ;
	}
	else
	{
		return S -> array[S -> top] ;
	}
}



int main()
{
	struct arrayStack *S = createStack(1) ;
	// now we have a stack of size 3 ;
	int o , q =1;
	while(q)
	{
		printf("Enter 1 to Push Element\nEnter 2 to Pop an Element\nEnter 3 to display the top element\nEnter 4 to EXIT ---> ");
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
				if(d != INT_MIN)
				{
					printf("Popped Element is : %d\n", d);
				}
				break ;
			}
			case 3 :
			{
				int t = top(S) ;
				if(t == INT_MIN)
					printf("Stack is Empty\n");
				else
					printf("Top element of the stack is %d\n", t );
				break ;
			}
			case 4 :
			{
				q = 0 ;
			}
		}
	}
}