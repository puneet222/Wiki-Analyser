#include<stdio.h>

void stackGrowth(int *temp1)
{
	int temp2 ;
	printf("Address of temp1 is %p\n", temp1);
	printf("Address of temp2 i %p\n",&temp2 );

	if(temp1 < &temp2)
		printf("Stack is growing downwards\n");
	else
		printf("Stack is growing upwards\n");
}

int testStackGrowth()
{
	int temp ;
	stackGrowth(&temp) ;
}

int main()
{
	testStackGrowth() ;
}