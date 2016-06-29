#include<stdio.h>
#include<malloc.h>

struct list{
	int data ;
	struct list *next ;
} ;

struct list *checkLoop(struct list *head)
{
	int loop = 0 ;
	struct list *slow , *fast ;

	slow = head ;
	fast = head ;

	while(slow != NULL && fast != NULL && fast -> next != NULL)
	{
		slow = slow -> next ;
		fast = fast -> next -> next;

		if(slow == fast)
		{
			loop = 1 ;
			break ;
		}	
	}

	if(loop)
	{
		printf("I'm in if\n");
		slow = head ;
		while(slow != fast)
		{
			slow = slow -> next ;
			fast = fast -> next ;
		}

		return slow ;
	}
	return NULL ;
}

int main()
{
	struct list *head = malloc(sizeof(struct list)) ;
	head -> data = 1 ;
	head -> next = NULL ;
	struct list * ptr  , *ptr2 ;
	ptr = head ;
	int i ;
	for(i = 2 ; i < 10 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = head ;
		head = newNode ;
	}

	ptr = head ;
	while(ptr != NULL)
	{
		printf("data is : %d\n", ptr -> data);
		ptr = ptr -> next ;
		
	}

	ptr = head ;
	for(i = 0 ; i < 4 ; i++)
	{
		ptr = ptr -> next ;
	}

	printf("Element at ptr is : %d\n", ptr -> data );

	ptr2 = head ;
	while(ptr2 -> next != NULL)
	{
		ptr2 = ptr2 -> next ;
	}

	printf("Element at ptr2 is : %d\n", ptr2 -> data );

	ptr2 -> next = ptr ;

	// above here we have a linked list containing the loop

	// now applying the algorithm to check whether the loop exists or not (Floyd Algorithm)

	struct list * res  = checkLoop(head) ;

	if(res == NULL)
		printf(" no Loop Exists\n");
	else
	{
		printf("LOOP IS THERE\n");
		printf("loop starts from %d\n", res->data );

		printf("--------------------------------------------------------------------------\n");
		printf("Loop is : \n");

		struct list *p ;
		p = res ;

		do{
			printf("Element of the loop is : %d\n" , p -> data);
			p = p -> next ;
		}
		while(p != res) ;
	}


}