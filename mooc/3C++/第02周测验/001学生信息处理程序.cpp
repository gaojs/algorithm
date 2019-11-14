#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
// 在此处补充你的代码
	private:
		static const int N=21;
		char name[N];
		int age,no;
		double first,second,third,fouth,average;

	public:
		void input() {
			char c;
			cin.getline(name,N,',');
			cin>>age>>c>>no>>c>>first>>c>>second>>c>>third>>c>>fouth;
		}

		void calculate() {
			average=(first+second+third+fouth)/4;
		}

		void output() {
			cout<<name<<","<<age<<","<<no<<","<<average<<endl;
		}
};

int main() {
	freopen("F:\\aain.txt","r",stdin);
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}

