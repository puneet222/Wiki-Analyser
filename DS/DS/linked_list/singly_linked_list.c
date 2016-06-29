#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list * next ;
};

void inserting(struct list **head , int data , int pos)
{
	struct list *p , *q ;
	int k = 0 ;
	p = *head ; 
	struct list* newNode = malloc(sizeof(struct list)) ;
		newNode -> data = data ;
	if(pos == 1)
	{
		newNode -> next = *head ;
		*head = newNode ;
	}
	else
	{
		while(p != NULL && k < pos)
		{
			k++ ;
			q = p ;
			p = p -> next ;
		}
		newNode -> next = p ;
		q->next = newNode ;
	}
}


void display(struct list *node)
{
	struct list* p = node ;

  while (p != NULL)
  {
     printf(" %d ", p->data);
     p = p->next;
  }
  printf("\n");
}

void deleting(struct list **head , int pos)
{
	struct list *p , *q ;
	int k = 0 ;
	p = *head ;
	if(pos == 1)
	{
		p = *head ;
		*head = p->next ;
		free(p) ;
	}
	else
	{
		while(p != NULL && k < pos-1)
		{
			k++ ;
			q = p ;
			p = p -> next ;
		}
		if(p == NULL)
		{
			printf("position does not exists\n");
		}
		else
		{
			q-> next = p-> next ;
		}
		free(p) ;
	}
}

int main()
{
	int d , p  , o , i;
	int q = 1 ;
	struct list *head = NULL ; 
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
				struct list *ptr = malloc(sizeof(struct list)) ;
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