#include "Cat.h"

void Cat::Talk()
{
	cout << "I am your cat and I feel ";

	int mood = Pet::GetMood(m_hunger, m_boredom);

	if (mood > 15) { cout << "mad"; }
	else if (mood > 10) { cout << "frustrated"; }
	else if (mood > 5) { cout << "okay"; }
	else { cout << "happy"; }

	cout << endl;

	Pet::PassingTime();
}