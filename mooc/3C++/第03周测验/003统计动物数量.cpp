#include <iostream>
using namespace std;

// 在此处补充你的代码
class Animal {
	public:
		static int number;
		Animal(){
			++number;
		}
		//delete c2要调用到Cat的析构函数
		virtual ~Animal(){
			--number;
		}
}; 

class Cat:public Animal {
	public:
		static int number;
		Cat(){
			++number;
		}
		~Cat(){
			--number;
		}
};

class Dog:public Animal {
	public:
		static int number;
		Dog(){
			++number;
		}
		~Dog(){
			--number;
		}
};

//必须在外面初始化
int Animal::number=0;
int Cat::number=0;
int Dog::number=0;

// 在此处补充你的代码
void print() {
	cout << Animal::number << " animals in the zoo, ";
	cout << Dog::number << " of them are dogs, ";
	cout << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete d3;
	delete c2;
	delete c3;
	print();
}

