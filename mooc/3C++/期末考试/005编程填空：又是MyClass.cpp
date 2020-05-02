#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;

// �ڴ˴�������Ĵ���
template<typename T> 
class CMyClass
{
	vector<T> v;
public:
	CMyClass(T* a, int n)
	{
		for(int i=0;i<n;i++)
		{
			v.push_back(a[i]);
		}
	}
	T operator [](int i)
	{
		return v[i];
	} 
};
// �ڴ˴�������Ĵ���

int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}
