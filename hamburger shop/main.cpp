/*
 * main.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */

#include <iostream>

using namespace std;

void startgame();
void setting();
void burgerMenue();
void instruction();
void credit();
void quitGame(bool&);

int main()
{
	int choice;
	bool endGame=false;
	//TODO write your welcome message
	cout<<"Welcome to Hamburger Shop Game\n";
	while(!endGame){
		cout<<"*** Game Menu ***\n";
		cout<<"[1] Start Game\n";
		cout<<"[2] Settings\n";
		cout<<"[3] Burger Menus\n";
		cout<<"[4] Instructions\n";
		cout<<"[5] Credits\n";
		cout<<"[6] Exit\n";
		cout<<"*****************\n";
		cout<<"Option (1 - 6):\n";

		while(!(cin>>choice)){
			cin.ignore();
			cin>>choice;
		}
		switch(choice){
			case 1: startgame(); break;
			case 2:	setting(); break;
			case 3: burgerMenue(); break;
			case 4: instruction(); break;
			case 5: credit(); break;
			case 6: quitGame(endGame); break;
			default: cout<<"wrong input"<<endl; break;
		}
	}

	cout<<"Game End, thx for playing"<<endl;
	return 0;
}



