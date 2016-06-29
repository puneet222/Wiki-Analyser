#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct list
{
	int data ;
	struct list *next ;
};

void push(struct list **head , int data)
{
	struct list *newNode = malloc(sizeof(struct list)) ;
	newNode -> data = data ;
	newNode -> next = NULL ;
	if(*head == NULL)
	{
		*head = newNode ;
		return ;
	}
	newNode -> next = *head ;
	*head = newNode ;
}

void display(struct list *head)
{
	if(head == NULL)
	{
		printf("Stack is Empty\n");
	}
	while(head != NULL)
	{
		printf(" %d ", head -> data );
		head = head -> next ;
	}
	printf("\n");
}

int pop(struct list **head)
{
	if(*head == NULL)
	{
		printf("Stack is empty\n");
		return INT_MIN ;
	}
	struct list *ptr = *head ;
	*head = ptr -> next ;
	ptr -> next = NULL ;
	return ptr -> data ;
}

int top(struct list *head)
{
	if(head == NULL)
	{
		printf("Stack is Empty\n");
		return INT_MIN ;
	}
	return head -> data ;
}

void deleteStack(struct list **head)
{
	if(*head == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	struct list *temp , *p ;
	p = *head ;
	while(p -> next != NULL)
	{
		temp = p -> next;
		p -> next = temp -> next ;
		free(temp);
	}
	free(p);
}

int main()
{
	struct list *head ;
	head = NULL ;
	int o , q = 1 , data;
	while(q)
	{
		printf("Enter 1 to push data\nEnter 2 to Pop data\nEnter 3 to display the top element\nEnter 4 to display the whole linked list\nEnter 5 to delete the stack\nEnter 6 to exit\n------------------>");
		scanf("%d" , &o) ;
		switch(o)
		{
			case 1 : 
			{
				printf("Enter the data : ");
				scanf("%d" , &data);
				push(&head , data) ;
				break ;
			}
			case 2 :
			{
				int d = pop(&head) ;
				if(d == INT_MIN)
					printf("--------------\n");
				else
				{
					printf("Popped element is  : %d\n" , d);
				}
				break ;
			}
			case 3 :
			{
				int t = top(head);
				if(t == INT_MIN)
					printf("--------------\n");
				else
				{
					printf("Top element is  : %d\n" , t);
				}
				break ;
			}
			case 4 :
			{
				display(head);
				break ;
			}
			case 5 :
			{
				deleteStack(&head) ;
			}
			case 6 : 
			{
				q = 0 ;
			}
		}
	}
}