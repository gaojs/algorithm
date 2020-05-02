#include <iostream>
#include <string>
using namespace std;

// 在此处补充你的代码
template (typename T)
class 
{
	
} 
// 在此处补充你的代码

int main() 
{
	int t;
	cin >> t;
	while( t -- ) { 
	    int b1[10];
	    for(int i = 0;i < 10; ++i) 		
	    	cin >> b1[i];
	    A<int, 10> a1 = b1;
	    cout << a1[2] << endl;
	    
	
	    double b2[5] ;
	    for(int i = 0;i < 5; ++i) 	
	    	cin >> b2[i];	    
	    A<double, 5> a2 = b2;
	    cout << a2.sum() << endl;
	
		
	    string b3[4] ;
	    for(int i = 0;i < 4; ++i) 	
	    	cin >> b3[i];	    
	    A<string, 4> a3 = b3;
	    cout << a3.sum() << endl;
	}
	return 0;
}
