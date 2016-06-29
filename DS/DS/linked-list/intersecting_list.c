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
		printf(" %d ", head -> data );
		head = head -> next ;
	}
}

void getIntersect(struct list *l1 , struct list *l2)
{
	struct list *head1 , *head2 ;
	int len1 = 0 ,len2 = 0 , diff = 0;
	head1 = l1 ; 
	while(head1 != NULL)
	{
		len1++ ;
		head1 = head1 -> next ;
	}
	head2 = l2 ;
	while(head2 != NULL)
	{
		len2++ ;
		head2 = head2 -> next ;
	}
	if(len1 < len2){
		head1 = l2 ;
		head2 = l1 ;
		diff = len2 - len1 ; 
	}
	else{
		head1 = l1 ;
		head2 = l2 ;
		diff = len1 - len2 ;
	}

	// now we have head1 pointing to longer list and head2 pointing to shorter list

	int i ; 
	for(i = 0 ; i < diff ; i++)
		head1 = head1 -> next ;

	while(head1 -> next != NULL  &&  head2 -> next != NULL)
	{
		if(head1 == head2)
		{
			printf("We got intersection at %d\n", head1 -> data);
			return ;
		}
		head1 = head1 -> next ;
		head2 = head2 -> next ;
	}
}


void findMid(struct list *head)
{
	struct list *ptr , *ptr2 ;
	ptr = head ; 
	ptr2 = head ;
	while(ptr2 -> next != NULL && ptr2 -> next -> next != NULL)
	{
		ptr = ptr -> next ;
		ptr2 = ptr2 -> next -> next;
	}

	printf("MID point at : %d\n", ptr -> data );
}



int main()
{
	struct list *l1 , *l2 , *l3 ;
	l1 = malloc(sizeof(struct list)) ;
	l2 = malloc(sizeof(struct list)) ;
	l3 = malloc(sizeof(struct list)) ;

	l1 -> data = 1 ;
	l2 -> data = 10 ;
	l3 -> data = 100 ;

	l1 -> next = NULL ;
	l2 -> next = NULL ;
	l3 -> next = NULL ;

	int i ;
	for(i = 2 ; i < 7 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i ;
		newNode -> next = l1 ;
		l1 = newNode ;
	}


	for(i = 2 ; i < 5 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i*10 ;
		newNode -> next = l2 ;
		l2 = newNode ;
	}


		for(i = 2 ; i < 4 ; i++)
	{
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = i*100 ;
		newNode -> next = l3 ;
		l3 = newNode ;
	}


	struct list *ptr , *ptr2 , *ptr3 ;
	ptr = l1 ;
	ptr2 = l2 ;
	ptr3 = l3 ;

	while(ptr -> next != NULL)
	{
		ptr = ptr -> next ;
	}

	while(ptr2 -> next != NULL)
	{
		ptr2 = ptr2 -> next ;
	}

	ptr -> next = ptr3 ;
	ptr2 -> next = ptr3 ;

	display(l1) ;

	findMid(l1) ; // this function find the mid element of the list with a single scan 

	printf("\n");

	display(l2) ;


	// here we have two lists that combined with third list

	ptr = l1 ;
	ptr2 = l2 ;

	int flag = 0 ;

	while(ptr -> next != NULL)
	{
		ptr2 = l2 ;
		while(ptr2 -> next != NULL)    // we find the intersecting node in complexity of O(nm) ;
		{
			if(ptr2 == ptr)
			{
				flag = 1 ;
				break ;
			}
			ptr2 = ptr2 -> next ;
		}
		if(flag == 1)
			break ;

		ptr = ptr -> next ;
	}

	printf("Both linked list joined at : %d\n", ptr -> data );

	// another approach to find the interecting node with complexity of max(O(n) , O(m))

	getIntersect(l1 , l2) ;

}