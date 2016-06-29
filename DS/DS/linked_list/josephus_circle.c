#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list * next ;
};

void display(struct list *head)
{
	while(head != NULL)
	{
		printf(" %d ", head -> data);
		head = head -> next ;
	}
}

void cdisplay(struct list *head)
{
	struct list *ptr ;
	ptr = head ;
	if(head == NULL)
		return ;
	do{
		printf(" %d ", ptr -> data);
		ptr = ptr -> next ;
	}
	while(ptr != head) ;
}

int josephusCircle(struct list *head , int k , int m)
{
	int i , j;
	struct list *ptr;
	ptr = head ;
	for(i = 1 ; i < k ; i++)
	{
		for(j = 0 ; j < m-1 ; j++)
		{
			head = ptr ;
			ptr = ptr -> next ;
		}
		head -> next = ptr -> next ;
		free(ptr) ;
		ptr = head -> next ;
	}
	return head -> data ;
}

int main()
{
	int k , i ,  m;
	printf("Enter number of persons : ") ;
	scanf("%d" , &k) ;
	printf("\nEnter value of m in josephus circle : ");
	scanf("%d" , &m);

	struct list *head = NULL , *ptr ;
	ptr = head ;

	for(i = 1 ; i <= k ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = NULL ;

		if(ptr == NULL)
		{
			ptr = newNode ;
			head = ptr ;
		}
		else
		{
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
	}

	ptr -> next = head ;

	// cdisplay(head) ;

	int res = josephusCircle(head , k , m) ;
	printf("Result after eliminating in josephus circle is : %d\n", res );
}