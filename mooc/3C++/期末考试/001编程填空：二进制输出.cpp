#include <iostream>
#include <string>
using namespace std;

string dec2bin(int x)
{
// 在此处补充你的代码
	string a;
	for(int i=30;i>=0;i--)
	{
		a.append(1,'0'+((x>>i)&0x01));
	} 
	return a;
// 在此处补充你的代码
}

int main(){
	int n;
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		cout << dec2bin(x) << endl;
	}
	return 0;
}
