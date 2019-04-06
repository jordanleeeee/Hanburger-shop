/*
 * ingredients.h
 *
 *  Created on: Apr 5, 2019
 *      Author: User3w
 */

#ifndef INGREDIENTS_H_
#define INGREDIENTS_H_

#include <iostream>

using namespace std;

struct Ingredient{
		string name;
		char Symbol;
		char symbol;
		void printDetail()const{
			if(name=="Mushroom"){
				cout<<name<<"\t"<<Symbol<<'/'<<symbol<<endl;
			}
			else{
				cout<<name<<"\t\t"<<Symbol<<'/'<<symbol<<endl;
			}
		}
};

Ingredient bread{"Bread", 'B', 'b'};
Ingredient cheese{"Cheese", 'C', 'c'};
Ingredient beef{"Beef", 'F', 'f'};
Ingredient lettuce{"Lettuce", 'L', 'l'};
Ingredient tomato{"Tomato", 'T', 't'};
Ingredient mushroom{"Mushroom", 'M', 'm'};
Ingredient egg{"Egg", 'E', 'e'};
Ingredient salmon{"Salmon", 'S', 's'};


#endif /* INGREDIENTS_H_ */
