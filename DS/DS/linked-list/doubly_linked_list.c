#include<stdio.h>
#include<malloc.h>

struct Dlist
{
	int data ;
	struct Dlist *prev ;
	struct Dlist *next ;
};

void inserting(struct Dlist **head , int data , int pos)
{
	struct Dlist *newNode = malloc(sizeof(struct Dlist)) ;
	newNode -> data = data ;
	struct Dlist *p , *q ;
	p = *head ;
	if(pos == 1)
	{
		
		newNode -> next = *head ;

		newNode -> prev = NULL ;

					if(*head)
					{
						printf("I'm in if \n");
						p -> prev = newNode ;
					}

		*head = newNode ;
	}

	else
	{
		p = *head ;
		int k = 0 ;
		while(p->next != NULL && k < pos-1)
		{
			k++ ;
			p = p -> next ;
		}
		if(k!=pos)
		{
			printf("Position doesn't exists\n");
		}
		else
		{
			newNode -> next = p -> next ;
			newNode -> prev = p ;

			if(p -> next)
			{
				p -> next -> prev = newNode ;
			}

			p -> next = newNode ;
		}
	}	

}

void deleting(struct Dlist **head , int pos)
{
	struct Dlist *ptr ;
	if(pos == 1)
	{
		ptr = *head ;
		*head = ptr -> next ;
		int del = ptr -> data ;
		free(ptr) ;
		printf("deleted value is %d\n", del );
	}
	else
	{
		ptr = *head ;
		int k = 0 ;
		while(ptr -> next != NULL  &&  k < pos-1)
		{
			k++ ;
			ptr = ptr->next ;
		}
		
		if(ptr -> next)
		{
			int del = ptr->data ;
			ptr -> prev -> next = ptr -> next ;
			ptr -> next -> prev = ptr -> prev ;
			free(ptr) ;
			printf("deleted element is : %d\n" , del);
		}
		else
		{
			int del = ptr -> data ;
			ptr -> prev -> next = NULL ;
			free(ptr) ;
			printf("deleted element is : %d\n" , del);
		}
	}
	
}


void display(struct Dlist *head)
{
	while(head != NULL)
	{
		printf("%d\n", head->data );
		head = head -> next ;
	}
}

int main()
{
	int d , p  , o , i;
	int q = 1 ;
	struct Dlist *head = NULL ; 
	while(q)
	{
		printf("Enter 1 for inserting into the linked list\nEnter 2 for deletion of element in the linked list \nEnter 3 to print the list \nEnter 4 to print the number of nodes \
			\nEnter 5 to exit :");
		scanf("%d",&o) ;


		

		switch(o)
		{
			case 1 :
			{
				printf("Enter the data : ") ;
				scanf("%d" , &d) ;
				printf("Enter the Position (if position greater than no. of nodes then the new node will be inserted in the last): ");
				scanf("%d" , &p) ;
				inserting(&head , d , p) ;
				break ;
			}

			case 2 :
			{
				printf("Enter the Position : ");
				scanf("%d" , &p) ;
				deleting(&head , p) ;
				break ;
			}

			case 3 :
			{
				display(head) ;
				break ;
			}

			case 4 :
			{
				int count = 0 ;
				struct Dlist *ptr;
				ptr = head ;
				while(ptr != NULL)
				{
					count++ ;
					ptr = ptr-> next ;
				}
				printf("Number of Nodes in the linked list are : %d\n" , count);
				break ;
			}

			case 5 :
			{
				q = 0 ;
			}
		}
	}

	return 0 ;

}