#include "Record.h"

Time::Time()
{
	year = month = day = hour = minute = second = 0;
}

void Time::setTime(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	second = s;
}

int Time::getYear()
{
	return year;
}
int Time::getMon()
{
	return month;
}
int Time::getDay()
{
	return day;
}
int Time::getHour()
{
	return hour;
}
int Time::getMin()
{
	return minute;
}
int Time::getSec()
{
	return second;
}

ostream& operator<<(ostream& output, const Time& t)
{
	output.setf(ios::right);
	output << t.year << "/";
	output.fill('0');
	output.width(2);
	output << t.month << "/";
	output.width(2);
	output << t.day << " ";
	output.width(2);
	output << t.hour << ":";
	output.width(2);
	output << t.minute << ":";
	output.width(2);
	output << t.second << "   ";
	return output;
}

Time& Time::operator=(Time t)
{
	year = t.year;
	month = t.month;
	day = t.day;
	hour = t.hour;
	minute = t.minute;
	second = t.second;
	return *this;
}

Player::Player()
{
	coin = 1500;
	card[21] = {};
	root = new Record;
	root->next = NULL;
}

Player::Player(string n)
{
	name = n;
	card[21] = {};
	coin = 1500;
	root = new Record;
	root->next = NULL;
}

void Player::setName(string n)
{
	name = n;
}

string Player::getName()
{
	return name;
}

void Player::addRecord(string result)
{
	Record* p = root;
	if (p->next != NULL)
	{
		while (p->next != NULL)//traverse to the last node
		{
			p = p->next;
		}
	}	
	Record* q = new Record;//node waiting to be added
	q->coin = coin;
	q->result = result;

	//get the current time
	struct tm t;
	time_t now;
	time(&now);      //get the date and time of the system
	localtime_s(&t, &now);   //get the local date and time
	q->time.setTime(t.tm_year + 1900,t.tm_mon+1,t.tm_mday,t.tm_hour,t.tm_min,t.tm_sec);

	q->next = NULL;
	p->next = q;
}

void Player::setRecord(Time t, int c, string r)
{
	Record* p = root;
	if (p->next != NULL)
	{
		while (p->next != NULL)//traverse to the last node
		{
			p = p->next;
		}
	}
	Record* q = new Record;//node waiting to be added
	q->coin = c;
	q->result = r;
	q->time = t;//That's why I overload the operator=
	q->next = NULL;
	p->next = q;
}

Record* Player::getRoot()
{
	return root;
}

void Player::traverseRecord()
{
	system("cls");
	cout << "Player:" << name << endl;
	if (root->next==NULL) cout << "Sorry, you haven't had record yet." << endl;
	else
	{
		Record* p = root;
		cout << "Time                  Result\tCoin\n";
		while (p->next != NULL)
		{
			p = p->next;
			cout << p->time;
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.fill(' ');
			cout.width(10);
			cout << p->result;
			cout << p->coin << endl;
		}
	}
	system("pause");
}

int Player::getCoin()
{
	return coin;
}
void Player::iniCoin(int c)
{
	coin = c;
}
void Player::setCoin(int d) // d = amount of change
{
	coin += d;
}
void Player::firstDeal(unsigned int deal1, unsigned int deal2)//I've changed this function. Pay attention to it.
{
	card[0] = deal1;
	card[1] = deal2;
}
int Player::getCard(int index)
{
	return card[index];
}
int Player::sumOfPoint()
{
	int sum = 0;
	for (int i = 0; i <= 20; i++)
		sum += card[i];
	return sum;
}
void Player::displayCard()
{
	for (int i = 0; i <= 20; i++)
	{
		if (card[i] != 0)
			cout << setw(5) << card[i];
	}
	cout << '\n';
}

void addPlayer(PlayerList* root, string n)
{
	PlayerList* p = root;
	if (p->next != NULL)
	{
		while (p->next != NULL)//traverse to the last node
		{
			p = p->next;
		}
	}
	PlayerList* q = new PlayerList;
	q->player = new Player(n);
	q->next = NULL;
	p->next = q;
	q->post = p;
}
// How to use?
// (in your main function)
// PlayerList* root = new PlayerList;//First declare the whole list
// root->next = NULL;//initialization of the PlayerList's root
// root->post=NULL;
// addPlayer(root, "KFC");//add any player you like

bool searchPlayerCheck(PlayerList* root, string n)
{
	bool flag = false;
	PlayerList* pl = root;
	while (pl->next != NULL)
	{
		pl = pl->next;
		if (pl->player->getName() == n)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

// ***IMPORTANT***
//before using this function, please check if there exists the player being to searched.
Player* searchPlayer(PlayerList* root, string n)
{
	PlayerList* pl = root;
	while (pl->next != NULL)
	{
		pl = pl->next;
		if (pl->player->getName() == n)
			break;
	}
	return pl->player;
}

//An Example
// 
//PlayerList* root = new PlayerList;
//root->next = NULL;
// root->post=NULL;
//addPlayer(root, "KFC");
//searchPlayer(root, "KFC")->addRecord("Win");
//searchPlayer(root, "KFC")->addRecord("Lose");
//
//addPlayer(root, "McDonald");
//Player* p1 = searchPlayer(root, "McDonald");//you can store this player to a Player* pointer for convenience
//p1->addRecord("Vivo50");
//
//searchPlayer(root, "KFC")->traverseRecord();
//p1->traverseRecord();

bool deletePlayer(PlayerList* root, string n)
{
	bool flag = false;
	PlayerList* pl = root;
	while (pl->next != NULL)
	{
		pl = pl->next;
		if (pl->player->getName() == n)
		{
			flag = true;
			pl->post->next = pl->next;
			if (pl->next != NULL) pl->next->post = pl->post;
			delete pl;
			break;
		}
	}
	return flag;
}