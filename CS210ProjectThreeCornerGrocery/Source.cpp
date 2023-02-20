#include <fstream>
#include <vector>
#include <iomanip>
#include <map>
#include "ProduceSales.h"
using namespace std;

typedef map<string, int> ItemsLog;     // map for storing data from file
ItemsLog frequency;     // map instance for counting item frequency, global because all menu functions need to access it

// function prototypes
void printMenu();
void itemSearch(string findItem);
void oneDayLog();
void oneDayHistogram();
void dailyItemLog();
void dataBackup();

int main() {
	int menuChoice = -1;     // variable for taking user menu choice, initialized to a non-existent menu option
	string searchItem = "none";     // variable for item search option, initialized to none which returns 0 results
	bool exit = false;

	system("Color 05");     // set background color to black and text color to dark purple
	
	dailyItemLog();     // open and read file data to map

	printMenu();     // print menu
	cout << endl;

	// loop through menu until user exits
	while (exit != true) {
		
		// validation loop
		while (true) {
			// prompt user for menu choice
			cout << "Please make a selection from the menu: ";
			cin >> menuChoice;
			cout << endl;

			// handle non numerical input
			if (cin.fail()) {
				cout << "Please only make a selection from the provided menu. Valid options are 1-4." << endl;
				// clear error state and buffer
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

			// handle numerical input outside the scope of the menu
			else if (menuChoice < 1 || menuChoice > 4) {
				cout << "Please only make a selection from the provided menu. Valid options are 1-4." << endl;
			}

			// break out of validation loop for valid input
			else {
				break;
			}
		}
		
		// check for exit choice
		if (menuChoice == 4) {
			exit = true;     // set exit condition to true
			break;     // break out of loop
		}

		// handle menu option 1
		if (menuChoice == 1) {
			cout << "Please enter the desired produce item to search for: ";
			cin >> searchItem;
			itemSearch(searchItem);
			cout << endl;
			printMenu();     // reprint menu for user convenience
		}

		// handle menu option 2
		if (menuChoice == 2) {
			oneDayLog();
			cout << endl;
			printMenu();     // reprint menu for user convenience
		}

		// handle menu option 3
		if (menuChoice == 3) {
			oneDayHistogram();
			cout << endl;
			printMenu();     // reprint menu for user convenience
		}
	}

	// exit condition response
	dataBackup();
	cout << "Data has been backed up, please enjoy your day!" << endl;

	return 0;
}

void dailyItemLog() {
	ifstream dailyFile;     // variable for opening/using file
	string produceItem;     // variable for pushing items to map

	dailyFile.open("CS210_Project_Three_Input_File.txt");     // open file
	// check if file was able to open, if not output error message
	if (!dailyFile.is_open()) {
		cout << "Error! Unable to open file!" << endl;
	}
	// if opening file is successful, write file data to map
	else {
		getline(dailyFile, produceItem);
		while (!dailyFile.fail()) {
			++frequency[produceItem];     // search map for item, increment count if exist, otherwise add item
			getline(dailyFile, produceItem);
		}

		// close file
		dailyFile.close();
	}

}

void dataBackup() {
	ofstream backup;     // variable for writing to file
	vector<ProduceSales*> dailySalesVector;     // vector of produce sale objects

	backup.open("frequency.dat");     // create & open backup file

	// check that file was opened
	if (!backup.is_open()) {
		cout << "Error! Unable to backup data!" << endl;
	}

	// loop through map creating a vector of produce sale objects
	for (ItemsLog::iterator count = frequency.begin(); count != frequency.end(); ++count) {
		ProduceSales* newProduceSalePointer = new ProduceSales();
		newProduceSalePointer->setItemName(count->first);
		newProduceSalePointer->setItemQuantity(count->second);
		dailySalesVector.push_back(newProduceSalePointer);
	}

	// loop through vector and print data to backup file
	for (int i = 0; i < dailySalesVector.size(); i++) {
		backup << dailySalesVector.at(i)->getItemName() << " - " << dailySalesVector.at(i)->getItemQuantity() << endl;
	}

	// deallocate memory occupied by vector
	for (int i = 0; i < dailySalesVector.size(); i++)
	{
		delete dailySalesVector[i];
	}
	//// for loop with iteration through map recording each key/value from beginning to end in backup file
	//for (ItemsLog::iterator count = frequency.begin(); count != frequency.end(); ++count) {
	//	backup << count->first << " - " << count->second << endl;
	//}

	backup.close();     // close file
}

void printMenu() {
	// print formatted menu header
	cout << "***********************************" << endl;
	cout << "*" << setw(34) << "*" << endl;     // use set width to make look pretty with even amounts of surrounding space
	cout << "*" << setw(19) << "MENU" << setw(15) << "*" << endl;
	cout << "*" << setw(34) << "*" << endl;
	cout << "***********************************" << endl;

	// print formatted menu options
	cout << "***********************************" << endl;
	cout << "*" << setw(34) << "*" << endl;
	cout << "*   1 Item Search" << setw(18) << "*" << endl;
	cout << "*   2 One Day Log" << setw(18) << "*" << endl;
	cout << "*   3 One Day Histogram" << setw(12) << "*" << endl;
	cout << "*   4 Exit" << setw(25) << "*" << endl;
	cout << "*" << setw(34) << "*" << endl;
	cout << "***********************************" << endl;
}

void itemSearch(string findItem) {
	if (frequency.find(findItem) != frequency.end()) {
		cout << findItem << " - " << frequency[findItem] << endl;
	}
	else {
		cout << "No purchase record found for " << findItem << endl;
	}
	
}

void oneDayLog() {
	// for loop with iteration through map printing each key/value from beginning to end
	for (ItemsLog::iterator count = frequency.begin(); count != frequency.end(); ++count) {
		cout << count->first << " - " << count->second << endl;
	}
}

void oneDayHistogram() {
	// iterate through map data printing each item and quantity of in histogram form
	for (ItemsLog::iterator count = frequency.begin(); count != frequency.end(); ++count) {
		cout << count->first << " ";
		// nested loop to print asterisks to match item quantity
		for (int i = count->second; i > 0; --i) {
			cout << "*";
		}
		cout << endl;
	}
}
