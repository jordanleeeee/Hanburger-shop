/*
 * burger_shop.h
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */

#ifndef BURGER_SHOP_H_
#define BURGER_SHOP_H_

#include "burger.h"

int MaxNumOrder=5;
const int TYPEOFBURGER=5;

class Shop{
	private:
		bool endGame;
		int numOrder;
		int maxNumOrder;
		int score;
		Burger** burger;
	public:
		Shop();
		~Shop();
		void addOneOrder();
		void randomlyAddOrder();
		void gameMenu();
		bool getGameStatus() const;
		void action();
		void removeCompletedOrder();
		void removeOutOfTimeOrder();
};

Shop::Shop(): endGame(false), numOrder(0), maxNumOrder(MaxNumOrder), score(10){
	burger=new Burger*[MaxNumOrder];
	for(int i=0; i<MaxNumOrder; i++){
		burger[i]=nullptr;
	}
}
Shop::~Shop(){
	cout<<"delete shop"<<endl;
	for(int i=0; i<MaxNumOrder; i++){
		delete burger[i];
	}
	delete[] burger;
	burger=nullptr;
}
void Shop::addOneOrder(){
	if(numOrder>=MaxNumOrder){
		return;
	}
	int randBurger = rand()% TYPEOFBURGER;
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
			delete burger[i];
			for(int j=i; j<numOrder-1; j++){
				burger[j]=burger[j+1];
			}
			numOrder--;
			return;
		}
	}
}
void Shop::removeOutOfTimeOrder(){
	for(int i=0; i<numOrder; i++){
		if(burger[i]->getRemainingTime()<0){
			delete burger[i];
			for(int j=i; j<numOrder-1; j++){
				burger[j]=burger[j+1];
			}
			numOrder--;
			score-=5;
		}
	}
}
void Shop::gameMenu(){		//process order page
	removeCompletedOrder();
	removeOutOfTimeOrder();
	randomlyAddOrder();
	cout<<"*** Order list ***"<<endl;
	for(int i=0; i<numOrder; i++){
		cout<<"Order #"<<i+1<<": "<<burger[i]->type<<" burger, ";
		cout<<burger[i]->burger_status<<", ";
		burger[i]->printRemainingTime();
	}
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Score: "<<score<<endl;
	cout<<"Enter [U] for update, [Q] for Quit, or [1-"<<numOrder<<"] for order: "<<endl;

	action();
}
bool Shop::getGameStatus() const{
	return endGame;
}
void Shop::action(){
	char choice;
	cin>>choice;
	if(choice=='U'||choice=='u'){
		return;
	}
	else if(choice=='Q'||choice=='q'){
		cout<<"confirm quit game?"<<endl;
		char input;

		bool valid=false;
		while(!valid){
			cin>>input;
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
			burger[num]->burgerOperation(num, score);
		}
		else{
			cout<<"wrong input...."<<endl;
		}
	}
}


#endif /* BURGER_SHOP_H_ */
