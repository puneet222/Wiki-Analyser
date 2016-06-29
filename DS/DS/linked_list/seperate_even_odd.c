#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list *next ;
};

void display(struct list *head)
{
	while(head != NULL)
	{
		printf(" %d ", head -> data);
		head = head -> next ;
	}
}

struct list *seperateEvenOdd(struct list *head)
{
	struct list *result = NULL , *ptr , *rptr ;
	ptr = head ;
	while(head != NULL)
	{
		if(result == NULL)
		{
			printf("NULL\n");
			head = head -> next ;
			ptr -> next = NULL ;
			result = ptr ;
			rptr = result ;
			ptr = head ;
		}
		else if( ( ptr -> data ) % 2 != 0)
		{
			printf("Second\n data is %d" , ptr -> data);
			head = head -> next ;
			ptr -> next = NULL ;
			rptr -> next = ptr ;
			rptr = rptr -> next ;
			ptr = head;
		}
		else
		{
			printf("last\n");
			head = head -> next ;
			ptr -> next = result ;
			result = ptr ;
			ptr = head ;
		}
	}
	return result ;
}

int main()
{
	int n ,m , i ;

	struct list *l1 = NULL , *ptr;

	for(i = 1 ; i <= 20 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = NULL ;
		if(l1 == NULL)
		{
			l1 = newNode ;
			ptr = l1 ;
		}
		else
		{
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
	}

	// display(l1) ;

	struct list *result = seperateEvenOdd(l1) ;
	display(result) ;
}