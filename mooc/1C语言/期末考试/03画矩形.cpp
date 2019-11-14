#include <iostream>
using namespace std;

int main(){
	int h,w,flag;
	char ch;
	
	cin>>h>>w>>ch>>flag;
//	cout<<h<<','<<w<<','<<ch<<','<<flag<<endl;
	for(int i=0;i<w;i++){//first
		cout<<ch;
	}
	cout<<endl;
	for(int j=1;j<h-1;j++){//middle 
		cout<<ch;//first
		for(int i=1;i<w-1;i++)
		if(flag) cout<<ch;
		else cout<<" ";
		cout<<ch<<endl;//last		
	}
	for(int i=0;i<w;i++){//last
		cout<<ch;
	}
	cout<<endl;	
	return 0;
}