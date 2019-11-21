#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
	public:
		int c,r;
		int **p;

		Array2():c(0),r(0),p(NULL) {
		} 
		Array2(int i, int j) {
			c=i,r=j;
			p=new int*[c];
			for(i=0; i<c; i++) {
				p[i]=new int[r];
			}
		}

		~Array2() {
			for(int i=0; i<c; i++) {
				delete []p[i];
			}
			delete []p;
		}

		Array2&operator=(const Array2 &b) {
		if (this == &b)
			return *this;
			if(p) {
				for(int i=0; i<c; i++) {
					delete []p[i];
				}
				delete []p;
			}
			c=b.c,r=b.r;
			p=new int*[c];
			for(int i=0; i<c; i++) {
				p[i]=new int[r];
				memcpy(p[i], b.p[i], sizeof(int)*r);
			}
			return *this;
		}
		
		int* operator[](int i) { //a[i][j]
			return p[i];
		}
		
		int operator()(int i, int j) { //a(i,j)
			return p[i][j];
		}
// 在此处补充你的代码
};

int main() {
	Array2 a(3,4);
	int i,j;
	for(  i = 0; i < 3; ++i )
		for(  j = 0; j < 4; j ++ )
			a[i][j] = i * 4 + j;
	for(  i = 0; i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << a(i,j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;
	b = a;
	for(  i = 0; i < 3; ++i ) {
		for(  j = 0; j < 4; j ++ ) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}
	return 0;
}
