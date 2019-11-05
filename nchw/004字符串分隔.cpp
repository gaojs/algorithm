#include<iostream> 
#include<string>
using namespace std;

int main()
{
	char s[256]={0};		
	while(cin.getline(s,sizeof(s)))
	{
		string str=string(s);
		for(int m=0;m<str.length();m+=8)
		{
			string sub =str.substr(m,8);
			if(sub.length()==8)
			{
				cout<<sub<<endl;
			}
			else //if(sub.length()>0)
			{
				while(sub.length()<8)
				{
					sub.append("0");
				}
				cout<<sub<<endl;
			} 
		}	
	}
	return 0;
}
