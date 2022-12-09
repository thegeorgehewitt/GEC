#include "Pet.h"

Pet::Pet(int hunger, int boredom)
{
	cout << "A new pet had arrived." << endl;
	m_hunger = hunger;
	m_boredom = boredom;
}

void Pet::Feed(int food)
{
	cout << "Chomp chomp chomp!" << endl;
	m_hunger -= food;
	
	if (m_hunger < 0) { m_hunger = 0; }

	PassingTime();
};

void Pet::Play(int fun)
{
	cout << "Yipee!" << endl;
	m_boredom -= fun;

	if (m_boredom < 0) { m_boredom = 0; }

	PassingTime();
};

void Pet::Talk()
{
	cout << "I am your pet and I feel ";

	int mood = GetMood(m_hunger, m_boredom);

	if (mood > 15) { cout << "mad"; }
	else if (mood > 10) { cout << "frustrated"; }
	else if (mood > 5) { cout << "okay"; }
	else { cout << "happy"; }

	cout << endl;

	PassingTime();
}

void Pet::PassingTime(int time)
{
	m_hunger += time;
	m_boredom += time;
}

Pet::~Pet(){};
