#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct stack
{
	int top;
	int capacity;
	int *array ;
};

struct stack *createStack(int size)
{
	struct stack *S = malloc(sizeof(struct stack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(S -> capacity * sizeof(int) ) ;
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
	S -> array[++S -> top] = data ;
}

int pop(struct stack *S)
{
	if(isEmpty(S))
	{
		return INT_MIN ;
	}
	else
	{
		int d = S -> array[S -> top] ;
		S -> top-- ;
		return d ;
	}
}

void insertAtbottom(struct stack *S , int data)
{
	int temp ;
	if(isEmpty(S))
	{
		push(S , data) ;
		return ;
	}
	else
	{
		temp = pop(S);
		insertAtbottom(S , data) ;
		push(S , temp) ;
	}
}

void reverseStack(struct stack *S)
{
	if(isEmpty(S))
		return ;
	int data = pop(S) ;
	reverseStack(S) ;
	insertAtbottom(S , data) ;
}



int main(int argc, char const *argv[])
{
	struct stack *S = createStack(3) ;
	//now we have a stack of size 3 ;
	int o , q =1;
	while(q)
	{
		printf("Enter 1 to Push Element\nEnter 2 to Pop an Element\nEnter 3 to reverse the stack \nEnter 4 to EXIT ---> ");
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
				else
				{
					printf("Stack Underflow\n");
				}
				break ;
			}
			case 3 :
			{
				reverseStack(S) ;
				break ;
			}
			case 4 :
			{
				q = 0 ;
			}
		}
	}
	return 0;
}