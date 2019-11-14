#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

template <class T>
class CArray3D {
// 在此处补充你的代码
	public:
		struct C2D {
			int y, z;
			T *p;

			void init(int m, int n) {
				y = m, z = n;
				p = new T[m*n];
			}
			T*operator[](int k) {
				return p+k*z;
			}
			//对象到指针的强制类型转换运算符
			operator T*() {
				return p;
			}
		};

		C2D *p;
		int x;

		CArray3D(int x, int y, int z) {
			p=new C2D[x];
			for (int i = 0; i < x; i++) {
				p[i].init(y,z);
			}
		}
		C2D &operator[](int i) {
			return p[i];
		}
// 在此处补充你的代码end
};

CArray3D<int> a(3,4,5);
CArray3D<double> b(3,2,2);

void PrintA() {
	for(int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 5; ++k)
				cout << a[i][j][k] << "," ;
			cout << endl;
		}
	}
}

void PrintB() {
	for(int i = 0; i < 3; ++i) {
		cout << "layer " << i << ":" << endl;
		for(int j = 0; j < 2; ++j) {
			for(int k = 0; k < 2; ++k)
				cout << b[i][j][k] << "," ;
			cout << endl;
		}
	}
}

int main() {
	int No = 0;
	for( int i = 0; i < 3; ++ i ) {
		a[i];
		for( int j = 0; j < 4; ++j ) {
			a[j][i];
			for( int k = 0; k < 5; ++k )
				a[i][j][k] = No ++;
			a[j][i][i];
		}
	}
	PrintA();
	memset(a[1],-1,20*sizeof(int));
	PrintA();
	memset(a[1][1],0,5*sizeof(int));
	PrintA();

	for( int i = 0; i < 3; ++ i )
		for( int j = 0; j < 2; ++j )
			for( int k = 0; k < 2; ++k )
				b[i][j][k] = 10.0/(i+j+k+1);
	PrintB();

	int n = a[0][1][2];
	double f = b[0][1][1];
	cout << "****" << endl;
	cout << n << "," << f << endl;
	return 0;
}
