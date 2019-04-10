#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pal_stack( char * );

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
	printf("enter a string: ");
	scanf("%s", str);
	
	//checking if the string is palindrome
	int result = pal_stack( str );

	//printing the result
	if( result == 1 )
		printf("YES, the string is palindrome!\n");
	else
		printf("NO, the string is NOT palindrome\n");

	return 0;
}

int pal_stack( char *str )
{
	//defining the declared stack	
	stack.top = -1;
	stack.s = ( char * )malloc( strlen(str)*sizeof(char) );

	//pushing string into the stack
	int n = strlen(str);
	for( int i=0; i<n; i++ )
		push( str[i] );

	//popping string out of the stack
	//*popping of alphabets from the stack reverses the string
	char rev_str[50];
	for( int i=0; i<n; i++ )
		rev_str[i] = pop();
	
	//checking if original string and reversed string are same
	if( strcmp( str, rev_str ) == 0 )
		return 1;
	else
		return 0;
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













