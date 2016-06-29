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
		printf(" %d " , head -> data);
		head = head -> next ;
	}
}

void insert(struct list **head ,  int data)
{
	struct list *newNode = malloc(sizeof(struct list)) ;
	newNode -> data = data ;
	newNode -> next = NULL ;
	struct list *ptr ;
	ptr = *head ;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next ;
	}
	ptr -> next = newNode ;
}

struct list *merge(struct list *head1 , struct list *head2)
{
	struct list *res , *ptr , *ptr2 ;
	res = head1 ;
	ptr = head1 ;
	ptr2 = head2 ;

	if(ptr -> data >= ptr2 -> data)
	{
		head2 = head2 -> next ;
		ptr2 -> next = ptr ;
		head1 = ptr2 ;
	}

	ptr2 = head2 ;
	// printf("test %d\n", ptr2 -> data );

	while(ptr  != NULL && ptr2 != NULL)
	{
		if(ptr -> next != NULL)
		{
			if(ptr -> next -> data > ptr2 -> data)
			{
				head2 = head2 -> next ;
				ptr2 -> next = ptr -> next ;
				ptr -> next = ptr2 ;
				printf("got location of 1 %d\n", ptr-> data );
				printf("got location second %d\n" , ptr2 -> data);
				ptr2 = head2 ;
			}
		}
		ptr = ptr -> next ;
		
	}

	if(head2) // if it contains some data  all will be greater
	{
		ptr = head1 ;
		while(ptr -> next != NULL)
		{
			ptr = ptr -> next ;
		}
		ptr -> next = head2 ;
	}
	else
	{
		printf("NO data\n");
	}

	// display(head1) ;
	res = head1 ;
}

int main()
{
	struct list *head1 = malloc(sizeof(struct list)) ;
	head1 -> data = 2 ;
	head1 -> next = NULL ;

	insert(&head1 , 5) ;
	insert(&head1 , 9) ;
	insert(&head1 , 10) ;
	insert(&head1 , 12) ;
	printf("list one is : \n");
	display(head1) ;

	struct list *head2 = malloc(sizeof(struct list)) ;
	head2 -> data = 1 ;
	head2 -> next = NULL ;

	insert(&head2 , 7) ;
	insert(&head2 , 11) ;
	insert(&head2 , 13) ;
	printf("list 2 is : \n");
	display(head2) ;

	printf("\n\n");

	struct list *res = merge(head1 , head2) ;
	display(res) ;
}