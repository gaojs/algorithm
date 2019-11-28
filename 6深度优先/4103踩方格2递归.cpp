//http://bailian.openjudge.cn/practice/4103/
//f(n)=f(n-1)+2*(f(n-2)+...+f(1)+f(0)+1);
#include <iostream>
using namespace std;
 
int f(int n)
{
	if (n <= 0)
	{//ÁÙ½çÌõ¼þ 
		return 1;
	}
	int m = f(n-1), s=1;	
	for(n-=2;n>=0;n--)
	{
		s+=f(n);
	}
	return m+2*s;
}

int main()
{
	int n;

	cin >> n;
	cout << f(n);
	return 0;
}
