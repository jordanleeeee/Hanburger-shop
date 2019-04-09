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
#include <iostream>

using namespace std;



enum Types{Cheese, Beef, Mushroom, Veggie, Salmon, Chicken};
enum Status{preparing, cooking, ready_to_serve, completed};

ostream& operator<<(ostream& os, const Types& t);
ostream& operator<<(ostream& os, const Status& s);

class Burger{
	private:
		Types type;
		Ingredient* ingredients;
		Status burger_status;
		int num_of_ingredients;
		int cooking_time;
		int timeStartCook;
		int initial_time;
		friend class Shop;
	public:
		Burger(Types);
		~Burger();
		int getRemainingTime(const int&) const;
		void printRemainingTime(const int&)const;
		void printBurgerInfo()const;
		void burgerOperation(const int&, int&, const int&);
		void preparingBurger(const int&, const int&);
		void cookingBurger(const int&);
		void ready_to_serveBurger(const int&, int&);
};





#endif /* BURGER_H_ */
