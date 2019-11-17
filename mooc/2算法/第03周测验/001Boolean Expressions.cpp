#include <cstring> 
#include <iostream>
#include <string>
using namespace std;

bool notExp(char a[], int n)
{
	if(n<=0) return false;
	else if(n==1)
	{
		switch(a[0])
		{
			case 'V': return true;
			case 'F': return false;
			default: return false;
		}
	}
	else if(n==2)
	{
		
	}
	
}

bool andExp(char a[], int n)
{
	if(n<=0) return false;
	
}

bool orExp(char a[], int n)
{
	if(n<=0) return false;
	
}

bool exp(string s, int n)
{
	if(n<=0) return false;
	return true;
}

int main()
{
	const int N = 100;
	char a[N] = {0};
	int n=0;
		 
	while(cin.getline(a, N))
	{
		cout<<"Expression "<<++n<<": ";
		if(exp(string(a), strlen(a)))
		{
			cout<<"V"<<endl;
		}
		else
		{
			cout<<"F"<<endl;
		}		
	}	
	return 0;
}
