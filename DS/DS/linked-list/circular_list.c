#include<stdio.h>
#include<malloc.h>

struct Clist
{
	int data ;
	struct Clist *next ;
};

void insertBegin(struct Clist **head , int data)
{
	struct Clist *newNode = malloc(sizeof(struct Clist)) ;
	struct Clist *ptr = *head;



	newNode -> data = data ;
	newNode -> next = newNode ;
	if(*head == NULL)
	{
		// printf("I'm in if\n");
		*head = newNode ;

	}
	else
	{
		// printf("I'm in elese\n");
		while(ptr -> next != *head){
			ptr = ptr -> next ;
		}
		newNode -> next = *head ;
		ptr -> next = newNode ;
		*head = newNode ;
	}
}

void insertEnd(struct Clist **head , int data)
{
	struct Clist *newNode = malloc(sizeof(struct Clist)) ;
	struct Clist *ptr ;
	ptr = *head ;
	newNode -> data = data ;
	newNode -> next = newNode ;

	if(*head == NULL)
	{
		*head = newNode ;
	}
	else
	{
		while(ptr -> next != *head)
		{
			ptr = ptr -> next ;
		}
		newNode -> next = *head ;
		ptr -> next = newNode ;
	}
}

void deleteStart(struct Clist **head)
{
	struct Clist *ptr ;
	ptr = *head ;

	while(ptr -> next != *head)
	{
		ptr = ptr -> next ;
	}

	ptr -> next = (*head) -> next ;
	ptr = *head ;
	*head = ptr -> next ;
	free(ptr) ;
}

void deleteEnd(struct Clist **head)
{
	struct Clist *ptr , *ptr2 ;
	ptr = *head ;
	while(ptr -> next != *head)
	{
		ptr2 = ptr ;
		ptr = ptr-> next ;
	}
	ptr2 -> next = ptr -> next ;
	free(ptr) ;
}

void display(struct Clist *head)
{
	struct Clist *ptr ;
	ptr = head ;
	if(head == NULL)
	{
		printf("No elements in the list\n");
	}
	else
	{
		do{
			printf(" %d \n", ptr -> data );
			ptr = ptr -> next ;
		}
		while(ptr != head) ;
	}
}

int main()
{
	int d  , o , i , q = 1 ;
	struct Clist *head = NULL ;

	while(q){
		printf("Enter 1 to insert at the begining\nEnter 2 to insert at the end\nEnter 3 to delete at the begining\nEnter 4 to delete at the end\nEnter 5 to print the list\nEnter 6 to exit");
		scanf("%d" , &o) ;

		switch(o)
		{
			case 1 :
			{
				printf("Enter the data : ");
				scanf("%d" , &d) ;
				insertBegin(&head , d) ;
				break ;
			}

			case 2 :
			{
				printf("Enter the data : ");
				scanf("%d" , &d) ;
				insertEnd(&head , d) ;
				break ;
			}

			case 3 :
			{
				deleteStart(&head) ;
				break ;
			}

			case 4 :
			{
				deleteEnd(&head) ;
				break ;
			}

			case 5 :
			{
				display(head) ;
				break ;
			}
		    
		    case 6 :
		    {
		    	q = 0 ;
		    }
		}	
	}

}