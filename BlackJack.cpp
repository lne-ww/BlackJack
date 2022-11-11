#include <iostream>
#include "BlackJack.h"
#include "Record.h"
#include "SaveAndLoad.h"
#include <ctime>
#include <random>
#include <iomanip>
using namespace std;

// a new method to generate random numbers in cpp 11
default_random_engine engine(static_cast<unsigned int>(time(0)));
uniform_int_distribution<unsigned int> randomInt1(1, 11), randomInt2(1, 9);

// status
enum Status { Continue, Win, Lost };

int main()
{
	PlayerList* root = new PlayerList;
	root->next = NULL;
	root->post = NULL;
	addPlayer(root, "KFC");
	searchPlayer(root,"KFC")->addRecord("Win");
	searchPlayer(root, "KFC")->addRecord("Lose");

	addPlayer(root, "McDonald");
	Player* p1 = searchPlayer(root, "McDonald");
	p1->addRecord("Vivo50");

	searchPlayer(root, "KFC")->traverseRecord();
	p1->traverseRecord();

	addPlayer(root, "Nahida");
	Player* p2 = searchPlayer(root, "Nahida");
	p2->addRecord("Dendro");

	deletePlayer(root, "McDonald");
	cout << searchPlayerCheck(root, "McDonald");

	p2->traverseRecord();

	//Save(root);

	/*Load(root);
	Player* p1 = searchPlayer(root, "McDonald");
	p1->traverseRecord();*/

	start();
}

//----------------Definition of functions


int correctInput(int input)
{
	if (cin.fail()) // true when cin fail
	{
		cin.clear(); // clear the failed status
		cin.ignore(1024, '\n'); // ignore the previous input
		cout << "Please input a correct number.\n";
		cin >> input;
		return correctInput(input); // recursion
	}
	else
		return input;
}
void start()
{
	Welcome welcome;
	welcome.displayWelcomeInfo();
	int choice1;
	cin >> choice1;
	while (1)
	{
		choice1 = correctInput(choice1); // correct the input from user
		welcome.setChoice(choice1); // set this integer in the class Welcome
		if (welcome.getChoice() == 2) // 2: Leave
			break;
		switch (welcome.getChoice())
		{
		case 0: // 0: Rule
			welcome.displayRule();
			cin >> choice1;
			break;
		case 1: // 1: Play
			chooseTable();// choose table
			break;
		default: // the integers besides 0, 1, 2 will go to this part
			cout << "Please input a correct number.\n";
			cin >> choice1; // reset the input
			break;
		}
		break;// input to new or quit
	}
}
void chooseTable()
{
	int choice2;
	cout << "There are two tables, 100 coin and 1000 coin ones." << endl
		<< "Table 1: Wanna play some CalicoJack? This is the 100 coin table." << endl
		<< "Table 2: This table's for the big shots. It's a 1000 coin bet." << endl
		<< "Choose one of them." << endl
		<< "1: Table 1\n2: Table 2" << endl << endl;
	cin >> choice2;
	while (1)
	{
		choice2 = correctInput(choice2); // correct the input from user
		switch (choice2)
		{
		case 1:
			table1();
			break;
		case 2:
			//table2();
			break;
		default:
			break;
		}
		break;
		break;// input to new or quit
	}
}
void table1()
{
	Player dealer, player;
	dealer.firstDeal(randomInt1(engine), randomInt2(engine));
	player.firstDeal(randomInt1(engine), randomInt2(engine));
	dealer.displayCard();
	player.displayCard();
}

// deal
int deal1()
{
	return randomInt1(engine);
}
int deal2()
{
	return randomInt2(engine);
}

// welcome
void Welcome::displayWelcomeInfo()
{
	cout << "Welcome to BlackJack!! This version is based on Stardew Valley.\n"
		<< "You have 1500 coins for bet now.\n"
		<< "0: Rule\n"
		<< "1: Play\n"
		<< "2: Leave\n";
}
void Welcome::setChoice(int c)
{
	choice = c;
}
int Welcome::getChoice()
{
	return choice;
}
void Welcome::displayRule()
{
	cout << "\nRule\n"
		<< "The objective is to get as close to 21 as possible.\n"
		<< "Cards range from 1 to 9, except for the first card\n"
		<< "which can be as high as 11. Each player starts with\n"
		<< "two cards, but the dealer's first card remains\n"
		<< "hidden.Each turn you can choose to draw a random\n"
		<< "number between 1 and 9 or pass.\n\n"
		<< "Once you pass, the dealer's hidden card is revealed.\n"
		<< "She must draw until her total reaches or exceeds 18.\n"
		<< "If either player exceeds 21 on their turn, they lose.\n"
		<< "If the dealer passes, then all cards are revealedand\n"
		<< "the highest score wins.\n\n"
		<< "You have 1500 coins for bet now.\n"
		<< "0: Rule\n"
		<< "1: Play\n"
		<< "2: Leave\n";
}

//player
//int Player::getCoin()
//{
//	return coin;
//}
//void Player::setCoin(int d) // d = amount of change
//{
//	coin += d;
//}
//void Player::firstDeal()
//{
//	card[0] = deal1();
//	card[1] = deal2();
//}
//int Player::getCard(int index)
//{
//	return card[index];
//}
//int Player::sumOfPoint()
//{
//	int sum = 0;
//	for (int i = 0; i <= 20; i++)
//		sum += card[i];
//	return sum;
//}
//void Player::displayCard()
//{
//	for (int i = 0; i <= 20; i++)
//	{
//		if (card[i] != 0)
//			cout << setw(5) << card[i];
//	}
//	cout << '\n';
//}
//
