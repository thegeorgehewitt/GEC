#ifndef CAT_H
#define CAT_H
#include "Pet.h"

class Cat : public Pet
{
public:
	Cat(int hunger, int boredom) : Pet(hunger, boredom) {}
	~Cat() {}
	void Talk();
private:
	int m_hunger = 0;
	int m_boredom = 0;
};

#endif