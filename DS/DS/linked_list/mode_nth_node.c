#include<stdio.h>
#include<malloc.h>
#include<math.h>

struct list
{
	int data ;
	struct list *next ;
};

void display(struct list *head)
{
	while(head != NULL)
	{
		printf(" %d ", head -> data );
		head = head -> next ;
	}
}

struct list *modularNodeFromBegin(struct list *head , int k)
{
	struct list *ptr , *result ;
	ptr = head ;
	int i = 1 ;

	if(k <= 0)
		return NULL ;

	while(ptr != NULL)
	{
		if(i%k == 0)
		{
			result = ptr ;
		}
		ptr = ptr -> next ;
		i++ ;
	}
	printf("value at ptr is %d\n" , result -> data);
	return result ;
}

struct list *modularNodeFromEnd(struct list *head , int k)
{
	struct list *ptr , *ptr2 , *result = NULL ;
	ptr = head ;
	if(k <= 0)
	{
		return NULL ;
	}
	int i = 1 ;
	while(ptr != NULL)
	{
		if(i % k == 0)
		{
			break ;
		}
		ptr = ptr -> next ;
		i++ ;
	}
	ptr2 = head ;
	while(ptr -> next != NULL)
	{
		ptr = ptr -> next ;
		ptr2 = ptr2 -> next ;
	}
	result = ptr2 ;
	return result ;
}

struct list *fractionalNode(struct list *head , int k)
{
	struct list *result = NULL , *ptr ;
	ptr = head ;

	if(k <= 0)
		return NULL ;
	int i = 1 ;

	while(ptr != NULL)
	{
		if(i%k == 0)
		{
			if(result == NULL)
			{
				result = head ;
			}
			else
			{
				result = result -> next ;
			}
		}
		ptr = ptr -> next ;
		i++ ;
	}

	return result ;
}

struct list *squareRootNode(struct list *head)
{
	struct list *ptr , *result = NULL;
	ptr = head ;
	int i = 1 , prev = 0 , next = 0 ;
	while(ptr != NULL)
	{
		prev = next ;
		int temp = sqrt(i) ;
		next = temp ;
		if(next > prev)
		{
			if(result == NULL)
			{
				result = head ;
			}
			else
			{
				result = result -> next ;
			}
		}
		i++ ;
		ptr = ptr -> next ;
	}

	return result ;
}

int main()
{
	struct list *head , *ptr ;
	head = NULL ;
	int i , k;
	for(i = 1 ; i < 21 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = NULL ;
		if(head == NULL)
		{
			head = newNode ;
			ptr = head ;
		}
		else
		{
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
	}

	// display(head) ;
	printf("Enter the value of k : ");
	scanf("%d" , &k);

	struct list *begin = modularNodeFromBegin(head , k) ;

	printf("Modular node from begin is %d with value of k is  : %d\n", begin -> data , k);

	struct list *end = modularNodeFromEnd(head , k) ;

	printf("Modular node from end is %d with value of k is  : %d\n", end -> data , k);

	struct list *frac = fractionalNode(head , k) ;
	printf("fraction node is : %d and the value of k is : %d\n", frac -> data , k );

	struct list *SQroot = squareRootNode(head) ;
	printf("SQRT(nth) node is %d\n" , SQroot -> data) ;




}