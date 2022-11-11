#include <iostream>

void start();
int correctInput(int); // this fuction is to avoid crash due to improper input, which returns a int type
void chooseTable();
void table1();
void table2();
int deal1();
int deal2();

// welcome
class Welcome
{
private:
	int choice;
public:
	void displayWelcomeInfo();
	void setChoice(int);
	int getChoice();
	void displayRule();
};