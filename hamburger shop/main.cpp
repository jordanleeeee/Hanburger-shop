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

		cin>>choice;
		switch(choice){
			case 1: startgame(); break;			//incomplete
			case 2:	setting(); break;			//complete
			case 3: burgerMenue(); break;		//complete
			case 4: instruction(); break;		//incomplete
			case 5: credit(); break;			//incomplete
			case 6: endGame=true; break;		//incomplete
			default: cout<<"wrong input"<<endl; break;
		}
	}
	cout<<"Game End, thx for playing"<<endl;
	return 0;
}



