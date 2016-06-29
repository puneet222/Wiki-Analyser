// this is basically second version of advanced stack in which memory efficiency is kept

#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct stack{
	int top ;
	int capacity;
	int *array ;
};

struct advancedStack
{
	struct stack *main ;
	struct stack *min ;	
};

struct stack *createStack(int size)
{
	struct stack *S = malloc(sizeof(struct stack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(S -> capacity * sizeof(int)) ;
	return S ;
}

struct advancedStack *createAdvancedStack()
{
	struct advancedStack *AS = malloc(sizeof(struct advancedStack)) ;
	AS -> main = createStack(5) ;
	AS -> min = createStack(5) ;
	return AS ;
}

int isEmpty(struct advancedStack *AS)
{
	return ((AS -> main)->top == -1) ;
}

int isFull(struct advancedStack *AS)
{
	return ((AS -> main) -> top == (AS -> main) -> capacity - 1) ;
}

void push(struct advancedStack *AS , int data)
{
	if(isFull(AS))
		{
			printf("StackOverflow\n");
			return ;
		}
	else
	{
		if(AS -> main -> top == -1) // first element
		{
			AS -> main -> array[++(AS -> main -> top)] = data ;
			AS -> min -> array[++(AS -> min -> top)] = data ;
		}
		else
		{
			AS -> main -> array[++(AS -> main -> top)] = data ;
			if(AS -> min -> array[AS -> min -> top] > data)
			{
				AS -> min -> array[++(AS -> min -> top)] = data ;
			}
		}
	}
}

int pop(struct advancedStack *AS)
{
	if(isEmpty(AS))
		return INT_MIN ;
	else
	{
		int d = AS -> main -> array[AS -> main -> top] ;
		AS -> main -> top-- ;
		if(d == AS -> min -> array[AS -> min -> top])
			AS -> min -> top-- ;
		return d ;
	}
}

int getMinimum(struct advancedStack *AS)
{
	if(isEmpty(AS))
		return INT_MIN ;
	else
		return AS -> min -> array[AS -> min -> top] ;
}

int main()
{
	struct advancedStack *AS = createAdvancedStack() ;
	int o , q =1;
	while(q)
	{
		printf("Enter 1 to Push Element\nEnter 2 to Pop an Element\nEnter 3 to display the minimum element\nEnter 4 to display top element\nEnter 5 to EXIT ---> ");
		scanf("%d" , &o);
		switch(o)
		{
			case 1 :
			{
				int data ;
				printf("Enter the data : ") ;
				scanf("%d" , &data) ;
				push(AS,data) ;
				printf("Number of elements main stack is %d\nNumber of elements min stack is %d\n",AS -> main -> top + 1 , AS -> min -> top + 1);
				break ;
			}
			case 2 :
			{
				int d = pop(AS) ;
				if(d != INT_MIN)
				{
					printf("Popped Element is : %d\n", d);
				}
				else
				{
					printf("StackUnderflow\n");
				}
				break ;
			}
			case 3 :
			{
				int t = getMinimum(AS) ;
				if(t == INT_MIN)
					printf("Stack is Empty\n");
				else
					printf("Minimum element of the stack is %d\n", t );
				break ;
			}
			case 4 :
			{
				if(isEmpty(AS))
					printf("Array is Empty\n");
				else
				{
					int t = AS -> main -> array[AS -> main -> top] ;
					printf("Top Element of the stack is : %d\n",t );
				}
				break ;
			}
			case 5:
			{
				q = 0 ;
			}
		}
	}
}