#include <iostream>
#include <string>
#include"Header.h"

using namespace std;

void creditList() {
	cout << "1. Nhi Dihn" << endl;
	cout << "2. Zhang Haozhe" << endl;
	cout << "3. Jessie Huang" << endl;
	cout << "4. Teresa Cheung" << endl;
	cout << "5. James Boultinghouse" << endl;
	cout << "6. Thien Pham" << endl;

}

void userMenu(int* userNum) {

	while (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7))) {
		cout << "1. Add" << endl;
		cout << "2. Remove " << endl;
		cout << "3. Sort " << endl;
		cout << "4. Previous Items " << endl;
		cout << "5. Find Terms and Definition Modification" << endl;
		cout << "6. Credits " << endl;
		cout << "7. Quit " << endl;
		cout << endl;
		cout << "choice - ";
		cin >> *userNum;
		if (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7))) {

			cout << endl;
			cout << "Be serious." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			*userNum = 0;
			cout << endl;
		}
	}
}
int main() {
	int userInput;
	int* userNum = &userInput;


	do {
		userMenu(userNum);
		switch (*userNum) {
		case 1: {
			int chap = 0;
			string def = "?";
			string word = "?";
			cout <<"Input your word: "<< endl;
			cin >> word;
			cout << "Input the definition of this word: " << endl;
			cin.ignore();//Important!!!
			getline(cin,def);
			do {
				cout << "Input the chapter that this word is located: " << endl;
				cin >> chap;
				if (cin.fail()) {
					cout << "Your input is invalid." << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					*userNum = 0;
					cout << endl;
				}
				if ((chap != 2) && (chap != 1) && (chap != 3) && (chap != 4) && (chap != 5) && (chap != 6) && (chap != 7) && (chap != 9) && (chap != 10) && (chap != 11) && (chap != 13)) {
					cout << "Chapter # misinput. " << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					*userNum = 0;
					cout << endl;
				}
			} while ((cin.fail()) || ((chap != 2) && (chap != 1) && (chap != 3) && (chap != 4) && (chap != 5) && (chap != 6) && (chap != 7) && (chap != 9) && (chap != 10) && (chap != 11) && (chap != 13)));
			cout << endl;
			*userNum = 0;
			break;
		}case 2: {
			string weebs;
			cout << "Which word do you want to remove?" << endl;
			cin >> weebs;

			//some searching and removing function here you are welcome
			*userNum = 0;
			break;
		}case 3: {
			int selection = 0;
			do {
				cout << "1. Alphabetical" << endl;
				cout << "2. By Chapter in Book" << endl;
				cout << "3. Quit" << endl;
				cin >> selection;
				if (cin.fail()) {
					cout << "Invalid input." << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					*userNum = 0;
					cout << endl;
				}
				if ((selection != 1) && (selection != 2) && (selection != 3)) {
					cout << "Wrong number." << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					*userNum = 0;
					cout << endl;
				}
				if (selection == 1) {
					cout << "Oy" << endl;
				}
				if (selection == 2) {
					cout << "Oy Oy" << endl;
				}
			} while ((cin.fail()) || ((selection != 1) && (selection != 2) && (selection != 3)));
			*userNum = 0;
			break;
		}case 4: {
			cout << "4" << endl;
			*userNum = 0;
			break;
		}case 5: {
			cout << "5" << endl;
			*userNum = 0;
			break;
		}case 6: {
			creditList();
			*userNum = 0;
			break;
		}
		}userMenu(userNum);
	}while (*userNum != 7);

	return 0;
}
