#include "ProduceSales.h"

// default constructor
ProduceSales::ProduceSales() {
	itemName = "none";
	itemQuantity = -1;
}

// mutators and accessors for item names and quantities
void ProduceSales::setItemName(string itemSold) {
	itemName = itemSold;
}

string ProduceSales::getItemName() {
	return itemName;
}

void ProduceSales::setItemQuantity(int quantitySold) {
	itemQuantity = quantitySold;
}

int ProduceSales::getItemQuantity() {
	return itemQuantity;
}
