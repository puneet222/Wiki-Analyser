#include<stdio.h>
#include<malloc.h>

struct list
{
	int data ;
	struct list *next ;
};

void insert(struct list **head , int data)
{
	struct list *newNode , *ptr ;
	newNode = malloc(sizeof(struct list)) ;
	newNode -> data = data ;

	if(*head == NULL)
	{
		*head = newNode ;
		newNode -> next = NULL ;
	}
	else
	{
		newNode -> next = *head ;
		*head = newNode ;
	}
}

void display(struct list *head)
{
	struct list *ptr ;
	ptr = head ;
	while(ptr != NULL)
	{
		printf(" %d \n", ptr -> data );
		ptr = ptr -> next ;
	}
}

int mySearchLast(struct list *head , int node)  // ~ O(n) (with two scans)
{
	struct list *ptr ;
	ptr = head ;
	int l = 0 ;
	while(ptr != NULL){
		l++ ;
		ptr = ptr -> next ;
	}
	int sn = l + 1 - node ;
	if(sn <= 0)
		{
			printf("Not Enough nodes are present...\n");
			return ;
		}
	l = 0 ;
	ptr = head ;

	while(l < sn - 1)
	{
		l++ ;
		ptr = ptr -> next ;
	}

	int data = ptr -> data ;
}






void searchLast(struct list *head , int node)   // ~ O(n)  (with one scan)
{
	int i ;
	struct list *ptr , *ptr2 ;
	ptr = head ;
	ptr2 = head ;

	if(head == NULL)
	{
		printf("List is Empty\n");
		return ;
	}

	for(i = 0 ; i < node ; i++)
	{
		ptr = ptr -> next ;
		if(ptr == NULL)
		{
			printf("List Has not Enough nodes ...\n");
			return ;
		}
	}

	// printf("data at nth is : %d\n" , ptr -> data);

	while(ptr != NULL)
	{
		ptr = ptr -> next ;
		ptr2 = ptr2 -> next ;
	}

	printf("Your Searched element is : %d\n", ptr2 -> data );
}






int main()
{
	struct list *head = NULL ;

	struct list * ptr ;

	int d , q = 1 ;
	while(q){
		printf("Enter Data : ");
		scanf("%d"  , &d) ;
		insert(&head , d) ;
		printf("Press 1 to enter more \nPress 0 if done : ");
		scanf("%d" , &q) ;
	}

	display(head) ;
	int node ;
	printf("Enter the last node you want to search : \n");
	scanf("%d", &node) ;
	int s = mySearchLast(head , node) ;
	printf("result is %d\n", s );

	searchLast(head , node) ;
}