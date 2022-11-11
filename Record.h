#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

//待添加：搜索玩家、文件

class Time
{
public:
	Time();
	void setTime(int, int, int, int, int, int);
	int getYear();
	int getMon();
	int getDay();
	int getHour();
	int getMin();
	int getSec();
	friend ostream& operator<<(ostream&, const Time&);
	Time& operator=(Time);
private:
	int year, month, day, hour, minute, second;
};

struct Record
{
	Time time;
	int coin=0;
	string result;
	Record* next;
};

//suppose you separate the Player class and the Dealer class.
class Player
{
public:
	Player();
	Player(string);
	void setName(string);
	string getName();
	void addRecord(string);
	void setRecord(Time, int, string);//used when loading from file or you set as you like
	Record* getRoot();
	void traverseRecord();
	int getCoin();
	void iniCoin(int);//initialize the coin from saved file
	void setCoin(int);
	void firstDeal(unsigned int, unsigned int);
	int getCard(int);
	int sumOfPoint();
	void displayCard();
private:
	int coin;
	int card[21];
	string name;
	Record* root;//root node of this player's record
};

struct PlayerList
{
	Player* player;
	PlayerList* next;
	PlayerList* post;
};

void addPlayer(PlayerList*, string);

bool searchPlayerCheck(PlayerList*, string);

Player* searchPlayer(PlayerList*, string);

bool deletePlayer(PlayerList*, string);