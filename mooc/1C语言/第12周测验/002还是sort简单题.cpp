#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;
};

struct Rule1 {
	bool operator()( const int & a1,const int & a2) {
		int r1=a1%10,r2=a2%10;
		if(r1<r2) return true;
		else if(r1>r2) return false;
		else return a1>a2;
	}
};

struct Rule2 {
	bool operator()( const Point & a1,const Point & a2) {
		int r1=a1.x*a1.x+a1.y*a1.y,r2=a2.x*a2.x+a2.y*a2.y;
		if(r1<r2) return true;
		else if(r1>r2) return false;
		else if(a1.x<a2.x) return true;
		else if(a1.x>a2.x) return false;
		else return a1.y<a2.y;
	}
};


int main() {
	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0; i < 8; ++i)
		cout << a[i] << "," ;
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0; i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")";
	return 0;
}