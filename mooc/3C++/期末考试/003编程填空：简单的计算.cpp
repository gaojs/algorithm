#include <iostream>
using namespace std;

template <class T>
class Add{
public:
// �ڴ˴�������Ĵ���
	T t;
	
	Add(T tt):t(tt)
	{
	}
	
	Add(T& a, T& b)
	{//ת�����캯��
		t=a+b-t;
	}
	
	operator T()
	{//����ת���������Զ�����������=>�����������ͣ�
		return t;
	}
	//friend ostream&<<()
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
