#include <iostream>
#include <iomanip>
using namespace std;

double f(double x){
	double y=0.0;
	if(x>=0&&x<5){
		y=(2.5-x);
	} else if(x>=5&&x<10){
		y=2-1.5*(x-3)*(x-3);
	} else if(x>=10&&x<20){
		y=x/2.0-1.5;
	}
	return y;
}


int main(){
	double n;
	
	cin>>n;
//	cout.precision(3);
//	cout<<fixed<<setprecision(3)<<f(n);
//	cout.fill('0');//<<setfill('0'); 
	printf("%.3lf",f(n));
	return 0;
}
