#include <iostream>
using namespace std;

// �ڴ˴�������Ĵ���
class Animal {
	public:
		static int number;
		Animal(){
			++number;
		}
		//delete c2Ҫ���õ�Cat����������
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

//�����������ʼ��
int Animal::number=0;
int Cat::number=0;
int Dog::number=0;

// �ڴ˴�������Ĵ���
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

