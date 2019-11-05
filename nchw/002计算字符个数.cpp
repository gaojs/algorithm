#include<iostream> 
#include <algorithm>
using namespace std;

const int N=5000;
char s[N]={0},a;
int main()
{
	cin.getline(s, N);
	string str(s);
	cin>>a;
	
	transform(str.begin(),str.end(),str.begin(),::tolower);
	//cout<<str<<endl;
	a=tolower(a);
	//cout<<a<<endl;
	int n=0, c=0;
	while(true)
	{
		n=str.find_first_of(a,n);
        if(n==string::npos)
        {
            break;
        }
		c++;
		n++;
	}
	cout<<c;	
	return 0;
}
