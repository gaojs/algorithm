#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;

class Printer
{
// �ڴ˴�������Ĵ���
public:
	int n;
	Printer(int x):n(x){}
	
	void operator()(int a) {
        if (a > n)
        {
            cout << a << ",";
		}
    }
    
    void operator()(string a) {
        if (a.length() > n)
        {
            cout << a << ",";
		}
    }
}; 
// �ڴ˴�������Ĵ���

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n,x;
		cin>>x>>n;
		
		vector<int> intVec;
		for(int i = 0;i < n; ++i) {
			int y;
			cin >> y;
			intVec.push_back(y);
		}
		for_each(intVec.begin(), intVec.end(), Printer(x));
		cout<<endl;
		
		vector<string> strVec;
		for(int i = 0;i < n; ++i) {
			string str;
			cin >> str;
			strVec.push_back(str);
		}
		for_each(strVec.begin(), strVec.end(), Printer(x));
		cout<<endl;
	}
	return 0;
}

