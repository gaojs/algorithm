#include <iostream>
using namespace std;

class Sample {
	public:
		int v;
// ������գ�ʹ�����9 22 5
// �ڴ˴�������Ĵ���
		Sample(int n=0) {
			v=n;
		}

		Sample(const Sample &x) {
			v=x.v+2;
		}
// �ڴ˴�������Ĵ���
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
