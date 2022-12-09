#ifndef DOG_H
#define DOG_H
#include "Pet.h"

class Dog : public Pet
{
public:
	Dog(int hunger, int boredom) : Pet(hunger, boredom) {}
	~Dog() {}
	void Talk();
private:
	int m_hunger=0;
	int m_boredom=0;
};

#endif