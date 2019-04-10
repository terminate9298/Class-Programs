#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int str_rev( char * );
struct Stack
{
	int top;	
	char *s;
}stack;

void push( char );
char pop( );

int main()
{
	//asking for a string
	char str[50];
	printf("enter the string you want to reverse: ");
	scanf("%s", str);
	
	//reversing the string
	str_rev( str );

	//printing the reversed string
	printf("the reversed string is: ");
	puts( str );

	return 0;
}

int str_rev( char *str )
{
	//defining the declared stack	
	stack.top = -1;
	stack.s = ( char * )malloc( strlen(str)*sizeof(char) );

	//pushing string into the stack
	int n = strlen(str);
	for( int i=0; i<n; i++ )
		push( str[i] );

	//popping string out of the stack
	//*popping of elements starts from last alphabet of the string
	for( int i=0; i<n; i++ )
		str[i] = pop();

	return 1;
}

void push( char c )
{
	stack.top++;
	stack.s[ stack.top ] = c;
}

char pop()
{
	char c = stack.s[ stack.top ];
	stack.top--;
	return c;
}













