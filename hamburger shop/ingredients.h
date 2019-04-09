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
		void printIngredientName(){

			if(name=="Chicken"){
				string str1(name,0,4);
				string str2(name,6,7);
				cout<<str1<<'['<<Symbol<<']'<<str2<<", ";
			}
			else if (name=="Beef"){
				string str(name, 0, 3);
				cout<<str<<'['<<Symbol<<']'<<", ";
			}
			else{
				string str(name, 1);
				cout<<'['<<Symbol<<']'<<str<<", ";
			}
		}
};



#endif /* INGREDIENTS_H_ */
