#ifndef CS210PROJECTTHREECORNERGROCERY_PRODUCESALES_H_
#define CS210PROJECTTHREECORNERGROCERY_PRODUCESALES_H_

#include <iostream>
#include <string>
using namespace std;

class ProduceSales
{
public:
	ProduceSales();
	string getItemName();
	void setItemName(string itemSold);
	int getItemQuantity();
	void setItemQuantity(int quantitySold);

private:
	string itemName;
	int itemQuantity;
};

#endif // !CS210PROJECTTHREECORNERGROCERY_PRODUCESALES_H_
