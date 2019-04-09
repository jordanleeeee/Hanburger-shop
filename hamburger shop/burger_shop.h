/*
 * burger_shop.h
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */

#ifndef BURGER_SHOP_H_
#define BURGER_SHOP_H_

#include "burger.h"

class Shop{
	private:
		bool endGame;
		int numOrder;
		const int maxNumOrder;
		int score;
		const int typeOfBurger;
		const int timeLimit;
		Burger** burger;
	public:
		Shop(int, const int, int);
		~Shop();
		bool getGameStatus() const;
		int getScore() const;
		void addOneOrder();
		void randomlyAddOrder();
		void checkingLoss();
		void gameMenu();
		void action();
		void removeCompletedOrder();
		void removeOutOfTimeOrder();
};


#endif /* BURGER_SHOP_H_ */
