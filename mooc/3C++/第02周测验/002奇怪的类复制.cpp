#include <iostream>
using namespace std;

class Sample {
	public:
		int v;
// 程序填空，使其输出9 22 5
// 在此处补充你的代码
		Sample(int n=0) {
			v=n;
		}

		Sample(const Sample &x) {
			v=x.v+2;
		}
// 在此处补充你的代码
};

void PrintAndDouble(Sample o) {
	cout << o.v;
	cout << endl;
}

int main() {
	Sample a(5);
//	cout << a.v<<endl;
	Sample b = a;
//	cout << b.v<<endl;
	PrintAndDouble(b);
	Sample c = 20;
	PrintAndDouble(c);
	Sample d;
	d = a;
	cout << d.v;
	return 0;
}
