// CPP program to check if parenthesis are 
// balanced or not in an expression. 
#include <bits/stdc++.h> 
using namespace std; 

char findClosing(char c) 
{ 
	if (c == '(') 
		return ')'; 
	if (c == '{') 
		return '}'; 
	if (c == '[') 
		return ']'; 
	return -1; 
} 

// function to check if parenthesis are 
// balanced. 
bool check(char expr[], int n) 
{ 
	// Base cases 
	if (n == 0) 
		return true; 
	if (n == 1) 
		return false; 
	if (expr[0] == ')' || expr[0] == '}' || expr[0] == ']') 
		return false; 

	// Search for closing bracket for first 
	// opening bracket. 
	char closing = findClosing(expr[0]); 

	// count is used to handle cases like 
	// "((()))". We basically need to 
	// consider matching closing bracket. 
	int i, count = 0; 
	for (i = 1; i < n; i++) { 
		if (expr[i] == expr[0]) 
			count++; 
		if (expr[i] == closing) { 
			if (count == 0) 
				break; 
			count--; 
		} 
	} 

	// If we did not find a closing 
	// bracket 
	if (i == n) 
		return false; 

	// If closing bracket was next 
	// to open 
	if (i == 1) 
		return check(expr + 2, n - 2); 

	// If closing bracket was somewhere 
	// in middle. 
	return check(expr + 1, i - 1) && check(expr + i + 1, n - i - 1); 
} 

// Driver program to test above function 
int main() 
{ 
	char expr[] = "[(])"; 
	int n = strlen(expr); 
	if (check(expr, n)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 

