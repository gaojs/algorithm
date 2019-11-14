#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
	double e=1,m=1;
	int n,i;
	
	cin>>n;
	for(i=0;i<n;i++){
		m*=i+1;
		e+=1/m;
	}	
	cout<<fixed<<setprecision(10)<<e;
	return 0;
}
