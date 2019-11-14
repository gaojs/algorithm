#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(
p=s;*p;p++
)
		cout << * p ;
	return 0;
}