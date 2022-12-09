#include "Hamster.h"

void Hamster::Talk()
{
	cout << "I am your hanster and I feel ";

	int mood = Pet::GetMood(m_hunger, m_boredom);

	if (mood > 15) { cout << "mad"; }
	else if (mood > 10) { cout << "frustrated"; }
	else if (mood > 5) { cout << "okay"; }
	else { cout << "happy"; }

	cout << endl;

	Pet::PassingTime();
}