#ifndef PET_H
#define PET_H
#include <iostream>

using namespace std;

class Pet
{
public:
	Pet(int hunger, int boredom);
	~Pet();

	virtual void Talk();

	void Feed(int food = 4);
	void Play(int fun = 4);

private:
	int m_hunger = 0;
	int m_boredom = 0;

protected:
	int GetMood(int hunger, int boredom) const { return m_hunger + m_boredom; }
	void PassingTime(int time = 1);
};

#endif