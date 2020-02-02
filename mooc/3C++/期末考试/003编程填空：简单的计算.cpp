#include <iostream>
using namespace std;

template <class T>
class Add{
public:
// 在此处补充你的代码
	T t;
	
	Add(T tt):t(tt)
	{
	}
	
	Add(T& a, T& b)
	{//转换构造函数
		t=a+b-t;
	}
	
	operator T()
	{//类型转换函数（自定义数据类型=>基本数据类型）
		return t;
	}
	//friend ostream&<<()
// 在此处补充你的代码
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
