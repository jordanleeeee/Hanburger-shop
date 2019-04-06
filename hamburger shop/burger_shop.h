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

Burger cheeseBurger(Cheesse);
Burger beefBurger(Beef);
Burger mushroomBurger(Mushroom);
Burger veggieBurger(Veggie);
Burger salmonBurger(Salmon);

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
		void addOrder();
		void gameMenu();
		bool getGameStatus() const;
		void action();
};

Shop::Shop(): endGame(false), numOrder(0), maxNumOrder(MaxNumOrder), score(10){
	burger=new Burger*[MaxNumOrder];
	for(int i=0; i<MaxNumOrder; i++){
		burger[i]=nullptr;
	}
}
Shop::~Shop(){
	delete[] burger;
	burger=nullptr;
}
void Shop::addOrder(){
	int randBurger = rand()% TYPEOFBURGER;
	burger[numOrder++] = new Burger(static_cast<Types>(randBurger));
}
void Shop::gameMenu(){
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
		//do sth to update
	}
	else if(choice=='Q'||choice=='q'){
		endGame=true;
	}
	else{
		int num=choice-'0';
		num--;
		if(num>=0 && num<numOrder){
			burger[num]->burgerOperation(num);
		}
		else{
			cout<<"wrong input...."<<endl;
		}
	}
}



#endif /* BURGER_SHOP_H_ */
