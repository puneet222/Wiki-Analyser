#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list *next ;
};

void display(struct list *head)
{
	struct list *ptr = head ;
	while(ptr != NULL)
	{
		printf(" %d \n", ptr -> data );
		ptr = ptr -> next ;
	}
}

struct list *reverse(struct list *head)   // reversing the linked list 
{
	struct list *nextNode = NULL , *temp = NULL ;
	while(head)
	{
		nextNode = head -> next ;
		head -> next = temp ;
		temp = head ;
		head = nextNode ;
	}
	return temp ;
}

struct list *recursiveReverse(struct list *head)  // reversing the list with recursion
{
	if(head == NULL)
		return NULL ;
	if(head -> next == NULL)
		return head ;

		struct list *second ;
		second = head -> next ;
		head -> next = NULL ;
		struct list *reverseRest = recursiveReverse(second) ;
		second -> next = head ;
		return reverseRest ;
}

int main()
{
	struct list *head = malloc(sizeof(struct list)) ;
	head -> data = 1 ;
	head -> next = NULL ;

	struct list *ptr ;
	ptr = head ;
	int i = 0 ;
	for(i = 2 ; i < 10 ; i++)
	{
		if(i == 6)
			continue ;
		else
		{
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = i ;
			ptr -> next = newNode ;
			newNode -> next = NULL ;
			ptr = ptr -> next ;
		}
	}

	// inserting 6 in the linked list

	struct list *insrt = malloc(sizeof(struct list)) ;
	insrt -> data = 6 ;

	ptr = head ;
	while(ptr -> next -> data <= insrt -> data)
	{
		ptr = ptr -> next ;
	}


	insrt -> next = ptr -> next ;
	ptr -> next = insrt ;

	display(head) ;




	struct list *result = reverse(head) ;

	struct list *recRes = recursiveReverse(head) ;

	display(recRes);

	display(result) ;
}