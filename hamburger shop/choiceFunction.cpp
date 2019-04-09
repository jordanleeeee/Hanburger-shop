/*
 * choiceFunction.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */
#include <iostream>

using namespace std;

#include"burger_shop.h"
#include"burger.h"

int MaxNumOrder=5;
const int TYPEOFBURGER=6;
int TimeLimit=40;

void startgame(){
	Shop burgerShop(MaxNumOrder, TYPEOFBURGER, TimeLimit);
	int initialNumBurger = rand()% MaxNumOrder+1;			//when open the shop, randomly add order first
	for(int i=0; i<initialNumBurger; i++){
		burgerShop.addOneOrder();
	}
	while(!burgerShop.getGameStatus()){
		burgerShop.gameMenu();
		burgerShop.removeCompletedOrder();
		burgerShop.removeOutOfTimeOrder();
		burgerShop.randomlyAddOrder();
		burgerShop.checkingLoss();
	}
	cout<<"your final score is "<<burgerShop.getScore()<<endl;
	cout<<"Maybe you want to play the game again"<<endl<<endl;
}
//here is function relation to setting
void setTimeLimit(){
	int time;
	bool correct_input=false;

	while(!correct_input){
		cout<<"Your current time limit is "<<TimeLimit<<endl;
		cout<<"please enter and set the new time limit"<<endl;
		while(!(cin>>time)){
			cout<<"wrong input, must be a integer number"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}

		if(time<=300 && time>0){
			TimeLimit=time;
			cout<<"now the time limit of order has set to be "<<TimeLimit<<endl;
			correct_input=true;
			system("pause");
		}
		else{
			cout<<"please enter a time value in range of 1 to 300 inclusively"<<endl<<endl;
		}
	}
}
void setMaxNumOrder(){
	int num;
	bool correct_input=false;
	while(!correct_input){
		cout<<"Your current max number of order is "<<MaxNumOrder<<endl;
		cout<<"please enter and set the new max number of order"<<endl;
		while(!(cin>>num)){
			cout<<"wrong input, must be a number"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		if(num>=1 && num<=50){
			MaxNumOrder=num;
			cout<<"now the max number of order has set to be "<<MaxNumOrder<<endl;
			correct_input=true;
			system("pause");
		}
		else{
			cout<<"please enter a number in range of 1 to 50 inclusively"<<endl<<endl;
		}
	}
}
void setting(){
	int choice;
	bool done=false;
	while(!done){
		cout<<"*** Settings Menu ***\n";
		cout<<"[1] Time limit ["<<TimeLimit<<" sec]\n";
		cout<<"[2] Max number of orders ["<<MaxNumOrder<<"]\n";
		cout<<"[3] Return to Game Menu\n";
		cout<<"*********************\n";
		cout<<"Option (1 - 3):\n";
		while(!(cin>>choice)){
			cout<<"wrong input, must be a number"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}

		switch(choice){
			case 1: setTimeLimit(); break;
			case 2: setMaxNumOrder(); break;
			case 3: done=true; break;
			default: cout<<"wrong input, please enter an number in between 1-3"<<endl; break;
		}
	}
}
//here is function relation to Display Burger Menu
void displayTypeBurger(){
	cout<<"Type of burger\tIngredients orders\t\t\t\tCooking time"<<endl;
	for(int i=0; i<TYPEOFBURGER; i++){
		Burger* burger=new Burger(static_cast<Types>(i));
		burger->printBurgerInfo();
		delete burger;
	}
	system("pause");
}
void displayIngredientSymble(){
	Ingredient bread{"Bread", 'B', 'b'};
	Ingredient cheese{"Cheese", 'C', 'c'};
	Ingredient beef{"Beef", 'F', 'f'};
	Ingredient lettuce{"Lettuce", 'L', 'l'};
	Ingredient tomato{"Tomato", 'T', 't'};
	Ingredient mushroom{"Mushroom", 'M', 'm'};
	Ingredient egg{"Egg", 'E', 'e'};
	Ingredient salmon{"Salmon", 'S', 's'};
	Ingredient chicken{"Chicken", 'K', 'k'};

	cout<<"Ingredients\tSymbol"<<endl;
	bread.printDetail();
	cheese.printDetail();
	beef.printDetail();
	lettuce.printDetail();
	tomato.printDetail();
	mushroom.printDetail();
	egg.printDetail();
	salmon.printDetail();
	chicken.printDetail();
	system("pause");
}
void burgerMenue(){
	bool done=false;
	int choice;
	while(!done){
		cout<<"**** Burger Menu *****\n";
		cout<<"[1] Types of Burger\n";
		cout<<"[2] Ingredient Symbols\n";
		cout<<"[3] Return to Game Menu\n";
		cout<<"*********************\n";
		cout<<"Option (1 - 3):\n";

		while(!(cin>>choice)){
			cout<<"wrong input, must be a number"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		switch(choice){
			case 1: displayTypeBurger(); break;
			case 2: displayIngredientSymble(); break;
			case 3: done=true; break;
			default: cout<<"wrong input, must be a number between 1-3"<<endl; break;
		}
	}
}

//TODO write instruction here
void instruction(){
	cout<<"write instruction here................."<<endl;
	system("pause"); // Wait until user pressing any key to continue

}

//TODO write your info here
void credit(){
	cout<<"Written by HKUST CSE Students"<<endl;
	system("pause"); // Wait until user pressing any key to continue
}

void quitGame(bool& endGame){

	cout<<"confirm quit game? (Y/N)"<<endl;
	char input;
	bool valid=false;
	while(!valid){
		while(!(cin>>input)){
			cout<<"wrong input, must be a char letter"<<endl;
			cin.clear();
			cin.ignore(100,'\n');
		}
		if(input=='y' ||input=='Y'){
			endGame=true;
			valid=true;
		}
		else if(input=='n' ||input=='N'){
			valid=true;
			return;
		}
		else{
			cout<<"please input Y/y/N/n"<<endl;
		}
	}
}


