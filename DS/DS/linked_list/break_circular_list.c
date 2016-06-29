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
	if(ptr == NULL)
		return ;
	do{
		printf(" %d " , ptr -> data);
		ptr = ptr -> next ;
	}
	while(ptr != head) ;
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

void breakList(struct list *head , struct list **l1 , struct list **l2)
{
	struct list *slow , *fast ;
	slow = head ;
	fast = head ;

	if(head == NULL)
		return ;
	while(fast -> next != head && fast -> next -> next != head)
	{
		fast = fast -> next -> next ;
		slow = slow -> next ;
	}


	if(fast -> next -> next == head)  // means fast pointer at second last position so we have to take it to last
	{
		fast = fast -> next ;
	}

	fast -> next = slow -> next ;
	*l2 = slow -> next ;
	slow -> next = head ;
	*l1 = head ;
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
	insert(&head1 , 19) ;

	struct list * ptr ;
	ptr = head1 ;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next ;
	}
	ptr -> next = head1 ;
	printf("list one is : \n");
	display(head1) ;
	printf("\n");

	struct list *l1 , *l2 ;
	l1 = NULL ;
	l2 = NULL ;

	breakList(head1 , &l1 , &l2) ;

	display(l1) ;
	printf("\n");
	display(l2);
}