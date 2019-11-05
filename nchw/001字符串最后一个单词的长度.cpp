#include<iostream> 
using namespace std;

const int N=5000;
char s[N]={0};
int main()
{
	cin.getline(s, N);
	string str(s);
	int n = str.rfind(" ");
	cout<<str.length()-(n+1);	
	return 0;
}
