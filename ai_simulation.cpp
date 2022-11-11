//This is a ai simulatition ver 1.0,an easy version
//Dealer have time to thing,ability to express his feeling to his cards
//To use this dealer ,just need to code "dealer()" in ur code
//Don't forget to add #include "ai_simulation.cpp"   :)
#include<stdlib.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <windows.h>
#include "ai_simulation.h"
#define SP1 100
#define SP5 500
using namespace std;


void dealer_action::comments(int a) { //say something to the situation
	int i =0;
	char say1[] = "I'm ready to make a big deal,and you?\n";
	char say2[] = "A good beginning,right?\n";
	char say3[] = "Well,I need some time.";
	char say4[] = "Good game.";
	char say5[] = "......\n";
	char say6[] = "I need one more card.\n";
	char say7[] = "The smaller,the more chance.\n";
	char say8[] = "Bad card,but don't care.\n";
	char say9[] = "Gonna to win,haha.\n";
	char say10[] = "Lucky 6.\n";
	char say11[] = "I stand.\n";


	switch(a) {
		case 1:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say1); i++) {
				cout<<say1[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 2:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say2); i++) {
				cout<<say2[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 3:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say3); i++) {
				cout<<say3[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 4:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say4); i++) {
				cout<<say4[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 5:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say5); i++) {
				cout<<say5[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 6:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say6); i++) {
				cout<<say6[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 7:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say7); i++) {
				cout<<say7[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 8:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say8); i++) {
				cout<<say8[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 9:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say9); i++) {
				cout<<say9[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 10:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say10); i++) {
				cout<<say10[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;

		case 11:
			cout<<"Dealer:";
			for (i=0; i<=strlen(say11); i++) {
				cout<<say11[i];
				Sleep(SP1);
			}
			Sleep(SP5);
			cout<<endl;
			break;
	}

};


void dealer_action::getcard(int turn) { //add a card to dealer's hand card
	srand(unsigned(time(NULL)));
	int rn = 1+rand()%9;
	dealer_card[turn-1] = rn;
}


int dealer_action::determine(int dealer_card[],int random,int d) {  //hit or stand
	int total = 0,final = 0;


	for(int i =0; i<10; i++) {					//sum up the point at present
		total += dealer_card[i];
	};



	if(total<=21&&total>=11) {             //Probabilistic selection
		int ar[10] = {0};
		int n = total,i = 0,a = 0,k;

		k = int(10*(21-n*1.0)/10+0.5);
		for (i=0; i<=k&&k != 0; i++) {
			ar[i] = 1;
		}

		final = ar[random];            //select stand or hit
	}


	if (total<13)final = 1;           //when the points below 11,dealer hit

	if(total>=21)final = 0;			//when the points larger than 21 ,dealer stand

	if(d == 1)final = total;      //when d = 1 ,return total points of dealer's hand cards

	return final;
}


int dealer_action::sumpoint() {                       //sumpoint

	int i= 0,total = 0;

	for(i=0; i<10; i++)
		total +=dealer_card[i];

	return total;
}


int dealer(int switch_1) {        //simulate a dealer.  If switch = 0,then start the game .If switch = 1,return the points.You can only return points after using the switch = 0 once.


	int turn=1;

	dealer_action Boy;

	if(switch_1 == 0) {
		Boy.comments(1);

		srand(time(0));
		for(turn=1; turn<6; turn++) {     			//dealer enter the game
			int rd = rand()%10;							//create a random number
			Boy.getcard(turn);

			if(Boy.dealer_card[1] == 0&&turn ==1) {					//this ling  print the first card of dealer
				cout<<"Dealer's first card is "<<Boy.dealer_card[0]<<endl<<endl;
			}

			//dealer's attitude to his card
			if(turn == 1) {											//In turn 1,judge the first between good or bad
				if(Boy.dealer_card[0] == 6)Boy.comments(10);
				if(Boy.dealer_card[0] == 8)Boy.comments(2);
				if(Boy.dealer_card[0] >0 &&Boy.dealer_card[0] <3)Boy.comments(8);
			}

			if(Boy.sumpoint()>14&&Boy.sumpoint()<19)Boy.comments(5);
			if(Boy.sumpoint()>=15&&Boy.sumpoint()<=17)Boy.comments(3);
			if(Boy.sumpoint()>=4&&Boy.sumpoint()<=6)Boy.comments(7);
			if(Boy.sumpoint()==20||Boy.sumpoint()==21)Boy.comments(9);

			if (Boy.determine(Boy.dealer_card,rd,0) == 0) {			//decide hit or stand
				Boy.comments(11);									//dealer stand
				break;
			} else {
				Boy.comments(6);                           		   //dealer need more card
			}
		}

	}

	if(switch_1 == 0) {										   		//return points
		return Boy.sumpoint();
	}
	return 0;
}
