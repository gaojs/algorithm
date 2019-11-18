#include <cstring> 
#include <iostream>
#include <string>
using namespace std;

bool orExp();
bool factor()
{//( 
	bool a = false;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '(':
			c = cin.get();
			a = orExp();
			c = cin.get();
			return (a);
		case 'V':
			c = cin.get();
			return true;
		case 'F':
			c = cin.get();
			return false;
		default:
			return false;
		}
	}	
}

bool notExp()
{//!
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '!':
			c = cin.get();
			return !notExp();
		case '=':
		default:
			return factor();
		}
	}		
}

bool andExp()
{//& 
	bool a = notExp(), b = false;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '&':
			c = cin.get();
			b = notExp();
			a = (a && b);
			break;
		case '=':
		default:
			return a;
		}
	}	
}

bool orExp()
{//|
	bool a = andExp(), b = false;
	while (true)
	{
		char c = cin.peek();
		switch (c)
		{
		case ' ':
			c = cin.get();
			continue;
		case '|':
			c = cin.get();
			b = andExp();
			a = (a || b);
			break;
		case '=':
		default:
			return a;
		}
	}
}

int main()
{
	const int N = 100;
	char a[N] = {0};
	int n=0;
		 
	do
	{
		if(orExp())
		{
			cout<<"Expression "<<++n<<": ";
			cout<<"V"<<endl;
		}
		else
		{
			cout<<"Expression "<<++n<<": ";
			cout<<"F"<<endl;
		}		
		cin.get();//»»ÐÐ 
	} while (cin.peek()!=EOF);
	return 0;
}
