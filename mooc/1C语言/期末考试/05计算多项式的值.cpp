#include<iostream>
#include<iomanip> 
using namespace std;

int main(){
	double f,s=1,p;
	int n,i;
	
	cin>>f>>n;
	for(i=0,p=f;i<n;i++){
		s+=p;
		p*=f;
	}	
	cout<<fixed<<setprecision(2)<<s;
	return 0;
}
