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

struct list *mergeSpecial(struct list *l1 , struct list *l2 )
{
	printf("I'm in function\n");
	struct list *temp = NULL, *result ;
	if(l1 == NULL)
		return l2 ;
	else if (l2 == NULL)
		return l1 ;
	else
	{
		printf("I'm in else\n");
		while(l1 != NULL && l2 != NULL)
		{
			if(temp == NULL)
			{
				temp = l1 ;
				result = temp ;
				l1 = l1 -> next ;
				temp -> next = l2 ;
				l2 = l2 -> next ;
				temp = temp -> next ;
			}
			else
			{
				temp -> next = l1 ;
				l1 = l1 -> next ;
				temp = temp -> next ;
				temp -> next = l2 ;
				l2 = l2 -> next ;
				temp = temp -> next ;
			}
		}
		if(l1)
		{
			temp -> next = l1 ;
		}
		display(result);

	}

}

int main()
{
	int n ,m , i ;
	printf("Enter  the length of !st and 2nd list : ") ;
	scanf("%d%d" , &n , &m) ;

	struct list *l1 = NULL , *ptr;
	struct list *l2 = NULL ;

	for(i = 1 ; i <= n ; i++)
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

	display(l1) ;

		for(i = 1 ; i <= m ; i++)
		{
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = i*10 ;
			newNode -> next = NULL ;
			if(l2 == NULL)
			{
				l2 = newNode ;
				ptr = l2 ;
			}
			else
			{
				ptr -> next = newNode ;
				ptr = ptr -> next ;
			}
		}

	display(l2) ;

	mergeSpecial(l1 , l2) ;
}