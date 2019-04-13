/*
 * burger_shop.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: User3w
 */
#include <ctime>
#include <iostream>

using namespace std;

#include "burger_shop.h"

Shop::Shop(int MaxNumOrder, const int TYPEOFBURGER, const int TimeLimit): endGame(false), numOrder(0),
		maxNumOrder(MaxNumOrder), score(10), typeOfBurger(TYPEOFBURGER), timeLimit(TimeLimit){
	burger=new Burger*[maxNumOrder];
	for(int i=0; i<maxNumOrder; i++){
		burger[i]=nullptr;
	}
}
Shop::~Shop(){
	//MAY HAVE PROBLEM
	for(int i=0; i<maxNumOrder; i++){
		delete burger[i];
	}
	delete[] burger;
	burger=nullptr;
}
void Shop::addOneOrder(){
	if(numOrder>=maxNumOrder){
		return;
	}
	int randBurger = rand()% typeOfBurger;
	burger[numOrder++] = new Burger(static_cast<Types>(randBurger));
}
void Shop::randomlyAddOrder(){
	//may change (New orders are generated randomly with a certain probability)
	int randNum = rand()% 5;		//0,1,2,3,4
	int randNumBurger=0;
	if(randNum==0 || randNum==1){
		randNumBurger = 0;
	}
	else if(randNum==2 || randNum==3){
		randNumBurger = 1;
	}
	else{
		randNumBurger = 2;
	}
	for(int i=0; i<randNumBurger; i++){
		addOneOrder();
	}
}
void Shop::removeCompletedOrder(){
	for(int i=0; i<numOrder; i++){
		if(burger[i]->burger_status==completed){
			burger[i]=nullptr;
			for(int j=i; j<numOrder; j++){
				burger[j]=burger[j+1];
			}
			burger[numOrder--]=nullptr;
			return;
		}
	}
}
void Shop::removeOutOfTimeOrder(){
	for(int i=0; i<numOrder; i++){
		if(burger[i]->getRemainingTime(timeLimit)<0){
			delete burger[i];
			burger[i]=nullptr;
			for(int j=i; j<numOrder; j++){
				burger[j]=burger[j+1];
			}
			burger[numOrder--]=nullptr;
			score-=5;
		}
	}
}
void Shop::checkingLoss(){
	if(score<0){
		cout<<"your score is below 0, GameOver"<<endl;
		endGame=true;
	}
}
void Shop::gameMenu(){		//process order page
	cout<<"*** Order list ***"<<endl;
	for(int i=0; i<numOrder; i++){
		cout<<"Order #"<<i+1<<": "<<burger[i]->type<<" burger, ";
		cout<<burger[i]->burger_status<<", ";
		burger[i]->printRemainingTime(timeLimit);
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Score: "<<score<<endl;
	cout<<"Enter [U] for update, [Q] for Quit, or [1-"<<numOrder<<"] for order: "<<endl;

	action();
}
int Shop::getScore()const{
	return (score<0)? 0: score;
}
bool Shop::getGameStatus() const{
	return endGame;
}
void Shop::action(){
	char choice;
	while(!(cin>>choice)){
		cout<<"wrong input, must be a one single letter or number"<<endl;
		cin.clear();
		cin.ignore(100,'\n');
	}
	if(choice=='U'||choice=='u'){
		return;
	}
	else if(choice=='Q'||choice=='q'){
		cout<<"confirm quit current game? (Y/N)"<<endl;
		char input;
		bool valid=false;
		while(!valid){
			while(!(cin>>input)){
				cout<<"wrong input, must be a single char letter"<<endl;
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
	else{
		int num=choice-'0';
		num--;
		if(num>=0 && num<numOrder){
			burger[num]->burgerOperation(num, score, timeLimit);
		}
		else{
			cout<<"wrong input...."<<endl;
		}
	}
}
