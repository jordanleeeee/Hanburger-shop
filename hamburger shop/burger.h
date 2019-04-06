/*
 * burger.h
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */

#ifndef BURGER_H_
#define BURGER_H_

#include "ingredients.h"
#include <cstdlib>
#include <ctime>

enum Types{Cheesse, Beef, Mushroom, Veggie, Salmon};
enum Status{preparing, cooking, ready_to_serve};

ostream& operator<<(ostream& os, const Types& t) {
    switch (t) {
        case Cheesse: os << "Cheesse"; break;
        case Beef: os << "Beef"; break;
        case Mushroom: os << "Mushroom"; break;
        case Veggie: os << "Veggie"; break;
        case Salmon: os << "Salmon"; break;
    }
    return os;
}

class Burger{
	private:
		Types type;
		Ingredient* ingredients;
		Status burger_status;
		int num_of_ingredients;
		int cooking_time;
		int initial_time;
		friend class Shop;
	public:
		Burger(Types);
		~Burger();
		void printBurgerInfo()const;

};

Burger::Burger(Types type): type(type) {

	//int randChoice= rand() % 5;	//0,1,2,3,4
	initial_time=time(0);
	burger_status=preparing;

	switch(type){
		case Cheesse: cooking_time=10;
					  num_of_ingredients=5;
					  ingredients=new Ingredient[num_of_ingredients];
					  ingredients[0]=bread;
					  ingredients[1]=cheese;
					  ingredients[2]=tomato;
					  ingredients[3]=lettuce;
					  ingredients[4]=bread;
					  break;
		case Beef: cooking_time=10;
				   num_of_ingredients=6;
				   ingredients=new Ingredient[num_of_ingredients];
				   ingredients[0]=bread;
				   ingredients[1]=cheese;
				   ingredients[2]=tomato;
				   ingredients[3]=beef;
				   ingredients[4]=lettuce;
				   ingredients[5]=bread;
				   break;
		case Mushroom: cooking_time=15;
					   num_of_ingredients=5;
					   ingredients=new Ingredient[num_of_ingredients];
					   ingredients[0]=bread;
					   ingredients[1]=cheese;
					   ingredients[2]=beef;
					   ingredients[3]=mushroom;
					   ingredients[4]=bread;
					   break;
		case Veggie: cooking_time=10;
					   num_of_ingredients=5;
					   ingredients=new Ingredient[num_of_ingredients];
					   ingredients[0]=bread;
					   ingredients[1]=tomato;
					   ingredients[2]=egg;
					   ingredients[3]=lettuce;
					   ingredients[4]=bread;
					   break;
		case Salmon: cooking_time=15;
					   num_of_ingredients=5;
					   ingredients=new Ingredient[num_of_ingredients];
					   ingredients[0]=bread;
					   ingredients[1]=cheese;
					   ingredients[2]=beef;
					   ingredients[3]=salmon;
					   ingredients[4]=bread;
					   break;
		default: cout<<"error"<<endl;
	}
}
Burger::~Burger(){
	delete[] ingredients;
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



#endif /* BURGER_H_ */
