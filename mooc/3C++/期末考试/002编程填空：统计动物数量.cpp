#include <iostream>
using namespace std;


// 在此处补充你的代码
struct Animal
{
	static int number;
	Animal()
	{
		number++; 
	} 
	virtual ~Animal()
	{
		number--; 
	} 
}; 
int Animal::number=0;

struct Dog:public Animal
{
	static int number;
	Dog()
	{
		number++; 
	} 
	~Dog()
	{
		number--; 
	} 
};
int Dog::number=0;

struct Cat:public Animal
{
	static int number;
	Cat()
	{
		number++; 
	} 
	~Cat()
	{
		number--; 
	} 
};
int Cat::number=0;
// 在此处补充你的代码

void print() {
	cout << Animal::number << " animals in the zoo, ";
	cout << Dog::number << " of them are dogs, ";
	cout << Cat::number << " of them are cats" << endl;
}

int main() {
	print(); //0 animals in the zoo, 0 of them are dogs, 0 of them are cats
	Dog d1, d2;
	Cat c1;
	print(); //3 animals in the zoo, 2 of them are dogs, 1 of them are cats
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print(); //6 animals in the zoo, 3 of them are dogs, 3 of them are cats
	delete c3;
	delete c2;
	delete d3;
	print(); //3 animals in the zoo, 2 of them are dogs, 1 of them are cats
}
