#ifndef MAMMALS_H
#define MAMMALS_H
#include <iostream>
using namespace std;

class Mammal
{
public:
	Mammal() : itsAge(1) {}
	~Mammal() {}

	virtual void Speak() const { cout << "Mammal speak!" << endl; }

protected:
	int itsAge;
};

class Dog : public Mammal
{
public:
	void Speak() const { cout << "Woof!" << endl; }
};

class Cat : public Mammal
{
public:
	void Speak() const { cout << "Meow!" << endl; }
};

class Horse : public Mammal
{
public:
	void Speak() const { cout << "Neigh!" << endl; }
};

class Pig : public Mammal
{
public:
	void Speak() const { cout << "Oink!" << endl; }
};

#endif