#include <iostream>
#include <string>
using namespace std;

string dec2bin(int x)
{
// �ڴ˴�������Ĵ���
	string a;
	for(int i=30;i>=0;i--)
	{
		if((x>>i)&0x01) a.append("1");
		else a.append("0");
	} 
	return a;
// �ڴ˴�������Ĵ���
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
