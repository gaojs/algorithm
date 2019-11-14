#include <iostream>
using namespace std;

class Point {
	private:
		int x;
		int y;
	public:
		Point() { };
// �ڴ˴�������Ĵ���
	friend istream&operator>>(istream &in, Point &p){
		in>>p.x>>p.y;
		return in;
	} 
	friend ostream&operator<<(ostream &out, Point &p){
		out<<p.x<<","<<p.y;
		return out;
	} 
};

int main() {
	Point p;
	while(cin >> p) {
		cout << p << endl;
	}
	return 0;
}

