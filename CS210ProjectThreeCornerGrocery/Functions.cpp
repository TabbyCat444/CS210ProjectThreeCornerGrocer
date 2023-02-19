#include "Functions.h"
#include <map>
using namespace std;

typedef map<string, int> ItemsLog;     // map for storing data from file
ItemsLog frequency;     // map instance for counting item frequency, global because it will be used in all following functions

// function to read file to map
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

void dataBackup() {
	ofstream backup;     // variable for writing to file

	backup.open("frequency.dat");     // create & open backup file
	
	// check that file was opened
	if (!backup.is_open()) {
		cout << "Error! Unable to backup data!" << endl;
	}

	// for loop with iteration through map recording each key/value from beginning to end in backup file
	for (ItemsLog::iterator count = frequency.begin(); count != frequency.end(); ++count) {
		backup << count->first << " - " << count->second << endl;
	}

	backup.close();     // close file
}