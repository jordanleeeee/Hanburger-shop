/*
 * burger.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: User3w
 */

#include <ctime>
#include <iostream>

using namespace std;

#include "burger.h"

Ingredient bread{"Bread", 'B', 'b'};
Ingredient cheese{"Cheese", 'C', 'c'};
Ingredient beef{"Beef", 'F', 'f'};
Ingredient lettuce{"Lettuce", 'L', 'l'};
Ingredient tomato{"Tomato", 'T', 't'};
Ingredient mushroom{"Mushroom", 'M', 'm'};
Ingredient egg{"Egg", 'E', 'e'};
Ingredient salmon{"Salmon", 'S', 's'};
Ingredient chicken{"Chicken", 'K', 'k'};

ostream& operator<<(ostream& os, const Types& t) {
    switch (t) {
        case Cheese: os << "Cheese"; break;
        case Beef: os << "Beef"; break;
        case Mushroom: os << "Mushroom"; break;
        case Veggie: os << "Veggie"; break;
        case Salmon: os << "Salmon"; break;
        case Chicken: os << "Chicken"; break;
    }
    return os;
}

ostream& operator<<(ostream& os, const Status& s) {
    switch (s) {
        case preparing: os << "preparing"; break;
        case cooking: os << "cooking"; break;
        case ready_to_serve: os << "ready to serve"; break;
        default:cout<<"error"<<endl;
    }
    return os;
}

Burger::Burger(Types type): type(type), timeStartCook(0){

	initial_time=time(0);
	burger_status=preparing;

	switch(type){
		case Cheese:
			cooking_time=10;
			num_of_ingredients=5;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=cheese;
			ingredients[2]=beef;
			ingredients[3]=lettuce;
			ingredients[4]=bread;
			break;
		case Beef:
			cooking_time=10;
			num_of_ingredients=6;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=cheese;
			ingredients[2]=tomato;
			ingredients[3]=beef;
			ingredients[4]=lettuce;
			ingredients[5]=bread;
			break;
		case Mushroom:
			cooking_time=15;
			num_of_ingredients=5;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=cheese;
			ingredients[2]=beef;
			ingredients[3]=mushroom;
			ingredients[4]=bread;
			break;
		case Veggie:
			cooking_time=10;
			num_of_ingredients=5;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=tomato;
			ingredients[2]=egg;
			ingredients[3]=lettuce;
			ingredients[4]=bread;
			break;
		case Salmon:
			cooking_time=15;
			num_of_ingredients=5;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=cheese;
			ingredients[2]=beef;
			ingredients[3]=salmon;
			ingredients[4]=bread;
			break;
		case Chicken:
			cooking_time=15;
			num_of_ingredients=5;
			ingredients=new Ingredient[num_of_ingredients];
			ingredients[0]=bread;
			ingredients[1]=tomato;
			ingredients[2]=chicken;
			ingredients[3]=cheese;
			ingredients[4]=bread;
			break;
		default: cout<<"error"<<endl;
	}
}
Burger::~Burger(){
	delete[] ingredients;
}
int Burger::getRemainingTime(const int& Time_limit)const{
	return Time_limit - (time(0)-initial_time);
}
void Burger::printRemainingTime(const int& TimeLimit)const{
	int times = getRemainingTime(TimeLimit);
	int mins=times/60;
	int seconds=times%60;
	if(times<0){
		mins=seconds=0;
	}
	cout<<mins<<"\'"<<seconds<<"\""<<endl;
}
void Burger::printBurgerInfo()const{
	cout<<type<<" burger"<<"\t";
	for(int i=0; i<num_of_ingredients; i++){
		cout<<ingredients[i].name;
		if(i!=num_of_ingredients-1){
			cout<<", ";
		}
	}
	if(type!=Beef){
		cout<<'\t';
	}
	cout<<"\t"<<cooking_time<<endl;
}
void Burger::burgerOperation(const int& num, int& score, const int& TimeLimit){
	switch(burger_status){
		case preparing:
			preparingBurger(num, TimeLimit);
			break;
		case cooking:
			cookingBurger(num);
			break;
		case ready_to_serve:
			cout<<"ready to serve"<<endl;
			ready_to_serveBurger(num, score);
			break;
		default:
			cout<<"error"<<endl;
	}
}
void Burger::preparingBurger(const int& num, const int& TimeLimit){
	cout<<"*** Process Order ***\n";
	cout<<"Order #\t\t\t: "<<num+1<<endl;
	cout<<"Burger\t\t\t: "<<type<< " Burger"<<endl;
	cout<<"Status\t\t\t: "<<burger_status<<endl;
	cout<<"Remaining Time\t\t: ";
	printRemainingTime(TimeLimit);
	cout<<"Burger Ingredient List\t:";
	for(int i=0; i<num_of_ingredients; i++){
		ingredients[i].printIngredientName();
	}
	cout<<endl;
	cout<<"Burger Key List\t\t:";
	for(int i=0; i<num_of_ingredients; i++){
		cout<<ingredients[i].symbol;
	}
	cout<<endl<<endl;
	cout<<"Please choose [U] for update, [R] for return, or\n";
	cout<<"type correct key list to start cooking:"<<endl;

	string input;
	cin>>input;
	if(input=="U" || input == "u"){
		preparingBurger(num, TimeLimit);
	}
	else if(input=="R" || input == "r"){
		return;
	}
	else{
		int num_of_correct=0;
		if(input.length()==static_cast<unsigned int>(num_of_ingredients)){
			for(int i=0; i<num_of_ingredients; i++){
				if(input[i]==ingredients[i].symbol){
					num_of_correct++;
				}
			}
		}
		if(num_of_correct==num_of_ingredients){
			cout<<"Cook success"<<endl;
			burger_status=cooking;
			timeStartCook=time(0);
		}
		else{
			cout<<"cook not successful, wrong correct key list"<<endl;
			preparingBurger(num,TimeLimit);
		}
	}
}
void Burger::cookingBurger(const int& num){
	cout<<"Order #\t"<<num+1<<endl;
	int remaining_time=cooking_time-(time(0)-timeStartCook);
	if(remaining_time>0){
		cout<<"the burger is being cooking"<<endl;
		cout<<"still need ["<<remaining_time<<" sec] to get ready"<<endl<<endl;
	}
	else{
		cout<<"the burger is cooked and get ready to serve"<<endl<<endl;
		burger_status=ready_to_serve;
	}
}
void Burger::ready_to_serveBurger(const int& num, int& score){
	cout<<"Order #\t"<<num+1<<endl;
	cout<<"order completed, well done"<<endl;
	burger_status=completed;
	score+=10;
}

