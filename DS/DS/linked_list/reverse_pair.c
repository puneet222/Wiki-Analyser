#include<stdio.h>
#include<malloc.h>

struct list{
	int data ;
	struct list *next ;
};

void insert(struct list **head ,  int data)
{
	struct list *newNode = malloc(sizeof(struct list)) ;
	newNode -> data = data ;
	newNode -> next = NULL ;
	if(*head == NULL)
	{
		*head = newNode ;
		return ;
	}
	struct list *ptr ;
	ptr = *head ;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next ;
	}
	ptr -> next = newNode ;
}

void display(struct list *head)
{
	while(head != NULL)
	{
		printf(" %d ", head -> data );
		head = head -> next ;
	}
}

struct list *reversePair(struct list *head)   // recursive approach
{
	struct list *ptr , *temp = head;
	if(head == NULL || head->next == NULL)
	{
		return head ;
	}
	else
	{
		ptr = temp -> next ;
		temp -> next = ptr -> next ;
		ptr -> next = temp ;
		temp = ptr ;
		temp -> next -> next = reversePair(temp -> next -> next) ;
		return temp ;
	}
	
}

struct list *iterativeReverse(struct list *head)
{
	printf("I'm in function") ;
	struct list *ptr1 = NULL , *ptr2 = NULL, *current ;
	current = head ;
	while(current != NULL && current -> next != NULL)
	{
		printf("In while loop\n");
		if(ptr2 != NULL)
		{
			ptr2 -> next -> next = current -> next ;
		}
		ptr2 = current -> next ;
		current -> next = current -> next -> next ;
		ptr2 -> next = current ;

		if(ptr1 == NULL)
		{
			printf("I'm in if\n");
			ptr1 = ptr2 ;
		}
		current =  current -> next ;
	}
	return ptr1 ;
}

int main()
{
	struct list *head = malloc(sizeof(struct list)) ;
	head = NULL ;
	insert(&head , 1) ;
	insert(&head , 2) ;
	insert(&head , 3) ;
	insert(&head , 4) ;
	insert(&head , 5) ;
	
	display(head) ;

	// struct list *result = reversePair(head) ;     // this is a call to recursive function
	// printf("\n");
	// display(result) ;

	display(head);

	struct list *result2 = iterativeReverse(head) ;
	printf("\n");
	display(result2);
}