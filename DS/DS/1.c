#include<stdio.h>
#include<string.h>

char arr[10] = ""; 

void Binary(int n){
	if(n < 1)
	{
		printf("%s\n", arr);
	}
	else
	{
		arr[n-1] = '0' ;
		printf("I am at before 1 i.e. at 0 and the value of n is %d\n" , n);
		Binary(n-1) ;
		arr[n-1] = '1' ;
		printf("I am at 1 i.e. at 1 and the value of n is %d \n" , n);
		Binary(n-1) ;
	}
}

main(){
	Binary(5) ;
}