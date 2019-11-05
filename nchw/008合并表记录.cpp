#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n,k,v;
	map<int,int> m;
	map<int,int>::iterator it; 

	cin>>n;
	m.clear();
	while(n--)
	{
		cin>>k>>v;
		it=m.find(k);
		if(it!=m.end())
		{
			it->second+=v;
		}
		else
		{
			m[k]=v;
		}
	}
	for(it = m.begin(); it!=m.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
