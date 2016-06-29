#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

struct Person{

	char * name ;
	int age ;
	int height ;
};

struct Person * create_Person(char *name , int age , int h)
{
	struct Person *who = malloc(sizeof(struct Person)) ;

	assert(who != NULL) ;

	who -> name = strdup(name) ;
	who -> age = age ;
	who -> height = h ;

	return who ;
}

void print_Person(struct Person * who)
{
	assert(who != NULL) ;

	printf("Name of the Person is : %s\n", who->name );
	printf("Age of the Person is : %d\n", who->age );
	printf("Height of the Person is : %d\n", who->height );
}

void destroy_Person(struct Person *who)
{
	assert(who != NULL) ;

	free(who) ;
}

int main()
{
	struct Person *Joe = create_Person("Joe" , 30 , 190) ;
	print_Person(Joe);

	destroy_Person(Joe);
}