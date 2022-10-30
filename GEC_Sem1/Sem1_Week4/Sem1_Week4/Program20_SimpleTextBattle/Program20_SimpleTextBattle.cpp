#include <iostream>
#include <windows.h>
using namespace std;

void chosenAttack(int a);
bool playState();

int playerHealth = 1000;
int enemyHealth = 2000;
char playAgain = 'y';
int attackType = 0;

int main()
{
	cout << "You find yourself within reach of freedom, a single troll challenging your escape!" << endl;
	Sleep(500);

	while (playState())
	{
		cout << "What kind of combat do you choose this round? 1. Sword  2. Magic  3. Axe?" << endl;
		cin >> attackType;
		while (attackType != 1 && attackType != 2 && attackType != 3)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Hmm that doesn't seem right, try entering 1, 2 or 3." << endl;
			cin >> attackType;
		}
		chosenAttack(attackType);
		Sleep(500);
	}
}

void chosenAttack(int a)
{
	const int sword_damage = 300, magic_damage = 650, axe_damage = 450, troll_sword = 350, troll_magic = 50, troll_axe = 100;

	switch (a) {
		case 1:
			enemyHealth -= sword_damage;
			playerHealth -= troll_sword;
			cout << "You and the troll hit each other with your attacks." << endl;
			Sleep(500);
			if (playerHealth < 0)
			{
				playerHealth = 0;
			}
			cout << "Your health is " << playerHealth << " and the troll's health is " << enemyHealth << "." << endl;
			break;
		case 2:
			enemyHealth -= magic_damage;
			playerHealth -= troll_magic;
			cout << "You and the troll hit each other with your attacks." << endl;
			Sleep(500);
			if (playerHealth < 0)
			{
				playerHealth = 0;
			}
			cout << "Your health is " << playerHealth << " and the troll's health is " << enemyHealth << "." << endl;
			break;
		case 3:
			enemyHealth -= axe_damage;
			playerHealth -= troll_axe;
			cout << "You and the troll hit each other with your attacks." << endl;
			Sleep(500);
			if (playerHealth < 0)
			{
				playerHealth = 0;
			}
			cout << "Your health is " << playerHealth << " and the troll's health is " << enemyHealth << "." << endl;
			break;
		default:
			break;
	}
}

bool playState()
{
	if (enemyHealth <= 0)
	{
		cout << "You killed the troll! You're finally free!" << endl;
		Sleep(500);
	}
	if (playerHealth <= 0)
	{
		cout << "You died! You'll never escape this place." << endl;
		Sleep(500);
	}
	
	if (playerHealth <= 0 || enemyHealth <= 0)
	{
		do
		{
			cout << "Do you want to play again? (y/n)" << endl;
			cin >> playAgain;
			playAgain = tolower(playAgain);

			if (playAgain == 'y')
			{
				playerHealth = 1000;
				enemyHealth = 2000;
				cout << "You find yourself within reach of freedom, a single troll challenging your escape!" << endl;
				Sleep(500);
				return true;
			}
			else if (playAgain == 'n')
			{
				return false;
			}
			else
			{
				cout << "That doesn't look right, make sure to enter 'y' or 'n'." << endl;
			}
		} while (playAgain != 'y' && playAgain != 'n');
	}

	return true;
}