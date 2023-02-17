#include <iomanip>
#include "MenuFunctions.h"
using namespace std;

// TODO: Create printMenu function
void printMenu() {
	// print formatted menu header
	cout << "***********************************" << endl;
	cout << "*" << setw(34) << "*" << endl;     // use set width to make look pretty with even amounts of surrounding space
	cout << "*" << setw(19) << "MENU" << setw(15) << "*" << endl;
	cout << "*" << setw(34) << "*" << endl;
	cout << "***********************************" << endl;

	// print formatted menu options

	// print formatted menu footer

}

// TODO: Menu option 1
/*
* Prompt a user to input the item, or word, they wish to look for.
* Return a numeric value for the frequency of the specific word.
*/

// TODO: Menu option 2
/*
* Print the list with numbers that represent the frequency of all items purchased.
* The screen output should include every item (represented by a word) paired with the number of
* times that item appears in the input file, CS210_Project_Three_Input_File.txt. For example, the file might read as follows:
* 		Potatoes 4
* 		Pumpkins 5
* 		Onions 3
*/

// TODO: Menu option 3
/*
* Print the same frequency information for all the items in the form of a histogram.
* Then print the name, followed by asterisks or another special character to represent the numeric amount.
* The number of asterisks should equal the frequency read from the CS210_Project_Three_Input_File.txt file.
* For example, if the file includes 4 potatoes, 5 pumpkins, and 3 onions, then your text-based histogram may
* appear as represented below. However, you can alter the appearance or color of the histogram in any way you choose:
* 		Potatoes ****
* 		Pumpkins *****
* 		Onions ***
*/

// TODO: Menu option 4
/*
* Exit the program.
*/