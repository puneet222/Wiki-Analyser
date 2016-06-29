#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list *next ;
};

struct stack 
{
	int top ;
	int capacity ;
	struct list * *array ;
};

struct stack *createStack(int size)
{
	struct stack *S = malloc(sizeof(struct stack)) ;
	S -> top = -1 ;
	S -> capacity = size ;
	S -> array = malloc(S -> capacity * sizeof(struct list)) ;
}

void push(struct stack *S , struct list *head)
{
	S -> array[++S -> top] = head ;
}

struct list *pop(struct stack *S)
{
	struct list *res  =  S -> array[S -> top] ;
	S -> top-- ;
}

void display(struct list *head)
{
	while(head != NULL)
	{
		printf(" %d \n", head -> data);
		head = head -> next ;
	}
}

int main()
{
	struct list *head = malloc(sizeof(struct list)) , *ptr ;;
	head -> data = 1 ;
	head -> next = NULL ;
	ptr = head ;
	int i ;
	for(i = 2 ; i < 11 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = NULL ;
		ptr -> next = newNode ;
		ptr = newNode ;
	}

	display(head) ;
	ptr = head -> next ;
	printf("address of ptr is %p\n" , ptr);
	struct stack *S = createStack(10) ;
	push(S , ptr) ;

	printf("head -> data is %d\n",ptr -> data );
	struct list *res = pop(S) ;
	printf(" cnkdjv d os %d\n", res->next->data);
}