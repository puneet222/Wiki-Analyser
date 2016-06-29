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

struct list *reverse(struct list *head)
{
	struct list *ptr , *temp ;
	ptr = head ;
	temp = NULL ;
	while(head != NULL)
	{
		head = head -> next ;
		ptr -> next = temp ;
		temp = ptr ;
		ptr = head ;
	}
	return temp ;
}

void insert(struct list **head , int data)
{
	struct list *newNode = malloc(sizeof(struct list)) , *ptr;
	newNode -> data = data ;
	newNode -> next = NULL ;
	ptr = *head ;
	if(*head == NULL)
	{
		*head = newNode ;
	}
	else
	{
		while(ptr -> next != NULL)
			ptr = ptr -> next ;

		ptr -> next = newNode ;
	}
}

struct list *addListData(struct list *l1 , struct list *l2)
{
	if(l1 == NULL)
		return l2 ;
	if(l2 == NULL)
		return l1 ;  
	int data , carry = 0  , sum;
	struct list *result = NULL  , *ptr;
	while(l1 != NULL && l2 != NULL)
	{
		sum = l1 -> data + l2 -> data + carry;
		data = sum % 10 ;
		carry = sum / 10 ;
		struct list *newNode = malloc(sizeof(struct list)) ;
		newNode -> data = data ;
		newNode -> next = NULL ;
		l1 = l1 -> next ;
		l2 = l2 -> next ;

		if(result == NULL)
		{
			result = newNode ;
			ptr = result ;
		}
		else
		{
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
	}
	if(l1)
	{
		while(l1 != NULL)
		{
			sum = l1 -> data + carry ;
			data = sum % 10 ;
			carry = sum / 10 ;
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = data ;
			newNode -> next = NULL ;
			l1 = l1 -> next ;
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
		if(carry > 0)
		{
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = carry ;
			newNode -> next = NULL ;
			ptr -> next = newNode ;
		}
	}
	if(l2)
	{
		while(l2 != NULL)
		{
			sum = l2 -> data + carry ;
			data = sum % 10 ;
			carry = sum / 10 ;
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = data ;
			newNode -> next = NULL ;
			l2 = l2 -> next ;
			ptr -> next = newNode ;
			ptr = ptr -> next ;
		}
		if(carry > 0)
		{
			struct list *newNode = malloc(sizeof(struct list)) ;
			newNode -> data = carry ;
			newNode -> next = NULL ;
			ptr -> next = newNode ;
		}
	}
	return result ;
}


int main()
{
	struct list *l1 = NULL , *l2 = NULL ;
	insert(&l1 , 2);
	insert(&l1 , 5);
	insert(&l1 , 0);

	printf("1st number is : \n");
	display(l1) ;
	printf("\n");

	insert(&l2 , 1);
	insert(&l2 , 8);
	insert(&l2 , 5);
	// insert(&l2 , 0);

	printf("2nd number is : \n");
	display(l2) ;
	printf("\n") ;

	struct list *revl1 = reverse(l1) ;
	struct list *revl2 = reverse(l2) ;

	struct list *revResult = addListData(revl1 , revl2);
	struct list *result = reverse(revResult) ;

	printf("result is : \n");
	display(result);

}