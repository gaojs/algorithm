#include <iostream>
using namespace std;

class A
{
	static int num;
public:
	A(){ num+=1; }
	
	void func()
	{
		cout<< num <<endl;
	}
// �ڴ˴�������Ĵ���
	A(const A& b) 
	{//���ƹ��캯�� Complex c2(c1);Complex c2 = c1;
		num--;
	}
	A& operator=(const A& a)
	{//��ֵ���캯��
	}
// �ڴ˴�������Ĵ���
};

int A::num=1;

int main()
{
	A a1; //2
	const A a2 = a1; //1
	A & a3 = a1; //1
	const A & a4 = a1; //0

	a1.func();//2
	a2.func();//1
	a3.func();//1
	a4.func();//0

	return 0;
}
