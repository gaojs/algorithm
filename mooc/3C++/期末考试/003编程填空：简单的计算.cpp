#include <iostream>
using namespace std;

template <class T>
class Add{
public:
// �ڴ˴�������Ĵ���
	T t;
    Add(T tt) :t(tt) {}
    
    T operator()(T x, T y) 
	{
        return (x + y - t);
    }
// �ڴ˴�������Ĵ���
};

int main(){
	double f;
	int n;
	while( cin >> f >> n) {
		
		Add<double> a1(f);
		Add<int> a2(n);
		double x,y;
		int p,q;
		cin >> x >> y >> p >> q;
		cout << a1(x, y) << endl;
		cout << a2(p, q) << endl;
	}
	return 0;
}
