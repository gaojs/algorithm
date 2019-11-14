#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
	private:
		double r,i;
	public:
		void Print() {
			cout << r << "+" << i << "i" << endl;
		}
// 在此处补充你的代码
		Complex() {
		}
		
		Complex(const char s[]) {
			sscanf(s, "%lf+%lfi", &r, &i);
		}
};

int main() {
	Complex a;
	a = "3+4i";
	a.Print();
	a = "5+6i";
	a.Print();
	return 0;
}
