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
// 在此处补充你的代码
	A(const A& b) 
	{//复制构造函数 Complex c2(c1);Complex c2 = c1;
		num--;
	}
	A& operator=(const A& a)
	{//赋值构造函数
	}
// 在此处补充你的代码
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
