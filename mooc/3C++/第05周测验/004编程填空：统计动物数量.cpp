#include <iostream>
using namespace std;

// �ڴ˴�������Ĵ���
class Animal {
	public:
		static int number;
		Animal() {
			number++;
		}
		//�������virtual,ɾ��c2��ʱ��Ͳ��ܵ���Cat������������
		virtual ~Animal() {
			number--;
		}
};

class Dog:public Animal {
	public:
		static int number;

		Dog():Animal() {
			number++;
		}
		~Dog() {
			number--;
		}
};

class Cat:public Animal {
	public:
		static int number;

		Cat():Animal() {
			number++;
		}
		~Cat() {
			number--;
		}
};

//��̬��Ա����ֻ���������ʼ���������������棡���� 
int Animal::number=0,Dog::number=0,Cat::number=0; 

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
