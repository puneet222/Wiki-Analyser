#include<stdio.h>
#include<malloc.h>

struct list
{
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
		printf(" %d ", head -> data);
		head = head -> next ;
	}
}

struct list *reverseList(struct list *head)
{
	struct list *temp , *nextNode ;
	temp = NULL ;
	while(head != NULL)
	{
		nextNode = head -> next ;
		head -> next = temp ;
		temp = head ;
		head = nextNode ;
	}
	return temp ;
}


struct list *reverseK(struct list *head , int k)
{
	int count = 0 ;
	struct list *ptr , *ptr2 ;
	ptr = head ;
	ptr2 = head ;
	while(count < k && ptr2 -> next != NULL)
	{
		count++ ;
		ptr2 = ptr ;
		ptr = ptr -> next ;
	}

	if(ptr2 == NULL)
	{
		printf("Not enough elements in the list...\n");
		return ;
	}

	if(ptr == NULL)
	{
		// printf("value of ptr2 is : %d\nValue of ptr is NULL", ptr2 -> data );
		struct list *result = reverseList(head) ;
		return result ;
	}
	else
	{
		// printf("value of ptr is : %d\n", ptr -> data );
		// printf("value of ptr2 is : %d\n", ptr2 -> data );
		ptr2 -> next = NULL ;
		struct list *result = reverseList(head) ;
		ptr2 = result ;
		while(ptr2 -> next != NULL)
		{
			ptr2 = ptr2 -> next ;
		}
		ptr2 -> next = ptr ;
		return result ;
	}
}


int main()
{
	struct list *head = NULL ;
	int i ;
	for(i = 1 ; i <= 10 ; i++)
	{
		insert(&head , i) ;
	}

	int k ;
	printf("Enter the number of element which you want to reverse : ");
	scanf("%d" , &k) ;

	struct list *result = reverseK(head , k) ;

	display(result) ;

}
