#include <iostream>
using namespace std;

class A {
	public:
		int val;

		A(int
// �ڴ˴�������Ĵ���
		  v=123) {
			val=v;
		}

		A &GetObj() {
			return *this;
		}
// �ڴ˴�������Ĵ���
};

int main() {
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}
