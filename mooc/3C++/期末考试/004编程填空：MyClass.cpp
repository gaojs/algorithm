#include <iostream>
using namespace std;

class CMyClassA 
{
private:
	int val;
public:
	CMyClassA(int);
	void virtual print();
};

CMyClassA::CMyClassA(int arg) 
{
	val = arg;
	printf("A:%d\n", val);
}

void CMyClassA::print() 
{
	printf("%d\n", val);
	return;
}


// 在此处补充你的代码
class CMyClassB:public CMyClassA 
{
private:
	int val;
public:
	CMyClassB(int v);	
	void virtual print();
};

CMyClassB::CMyClassB(int arg):CMyClassA(3*arg)
{
	val = arg;//*CMyClassA::val;
	printf("B:%d\n", val);
}

void CMyClassB::print() 
{
	printf("%d\n", val);
	return;
}
// 在此处补充你的代码


int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; 
	ptr->print();
	//A:3
	//A:15
	a = b;
	a.print();
	//B:5
	//3
	ptr = &b; 
	ptr->print();
	//15
	//5
	return 0;
}
