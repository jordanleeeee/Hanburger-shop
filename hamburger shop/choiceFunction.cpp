/*
 * choiceFunction.cpp
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */
#include <iostream>
using namespace std;

#include"burger_shop.h"

void startgame(){
	Shop burgerShop;
	int initialNumBurger = rand()% MaxNumOrder+1;
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
}
//here is function relation to setting
void setTimeLimit(){
	int time;
	bool correct_input=false;

	while(!correct_input){
		cout<<"Your current time limit is "<<TimeLimit<<endl;
		cout<<"please enter and set the new time limit"<<endl;
		cin>>time;

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
		cin>>num;
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
		cin>>choice;

		switch(choice){
			case 1: setTimeLimit(); break;
			case 2: setMaxNumOrder(); break;
			case 3: done=true; break;
			default: cout<<"wrong input"<<endl; break;
		}
	}

}
//here is function relation to Display Burger Menu
void displayTypeBurger(){
	cout<<"Type of burger\tIngredients orders\t\t\t\tCooking time"<<endl;
	Burger** burger=new Burger*[TYPEOFBURGER];
	for(int i=0; i<TYPEOFBURGER; i++){
		burger[i]=new Burger(static_cast<Types>(i));
		burger[i]->printBurgerInfo();
	}
	for(int i=0; i<TYPEOFBURGER; i++){
		delete burger[i];
	}
	delete[] burger;
	system("pause");
}
void displayIngredientSymble(){
	cout<<"Ingredients\tSymbol"<<endl;
	Burger x(Cheesse);
	bread.printDetail();
	cheese.printDetail();
	beef.printDetail();
	lettuce.printDetail();
	tomato.printDetail();
	mushroom.printDetail();
	egg.printDetail();
	salmon.printDetail();
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

		cin>>choice;
		switch(choice){
			case 1: displayTypeBurger(); break;
			case 2: displayIngredientSymble(); break;
			case 3: done=true; break;
			default: cout<<"wrong input"<<endl; break;
		}
	}
}

//TODO write instruction here
void instruction(){
	//system("cls");
	cout<<"write instruction here................."<<endl;
	system("pause"); // Wait until user pressing any key to continue

}

//TODO write your info here
void credit(){
	//system("cls");
	cout<<"cout sth.............."<<endl;
	system("pause"); // Wait until user pressing any key to continue
}


