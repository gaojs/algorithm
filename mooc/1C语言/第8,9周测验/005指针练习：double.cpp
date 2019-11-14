#include <iostream>
using namespace std;

void Double(int * p, int n)
{
	for(int i = 0;i < n; ++i)
		p[i] *= 2;
}


int main()
{
	int a[3][4] = { { 1,2,3,4},{5,6,7,8},
					{ 9,10,11,12 } };
	
	Double(
&a[1][0],6
);
	for(int i = 0;i < 3; ++i) {
		for(int j = 0; j < 4; ++j)
			cout << a[i][j] << ",";
		cout << endl; 
	}
	
	return 0;
}