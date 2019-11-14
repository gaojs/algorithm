#include <iostream>
#include <iomanip>
using namespace std;

double f(int n) {
	double p=1,q=2, r=0.0;
	for(;n>0;n--){
		r+=q/p;
		q=q+p;
		p=q-p;
	}
	return r; 
}

int main(){
	double n;
	
	cin>>n;
	cout<<fixed<<setprecision(4)<<f(n);
	return 0;
}
