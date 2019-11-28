//http://bailian.openjudge.cn/practice/4103/
//f(n)=f(n-1)+2(f(n-2)+...+f(1)+f(0))+2;
#include <iostream>
using namespace std;
 
int f(int n)
{
	if (n <= 0)
	{//ÁÙ½çÌõ¼þ 
		return 1;
	}
	int m = f(n-1);	
	for(n-=2;n>=0;n--)
	{
		m+=2*f(n);
	}
	m+=2;
	return m;
}

int main()
{
	int n;

	cin >> n;
	cout << f(n);
	return 0;
}
