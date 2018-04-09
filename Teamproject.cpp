#include <iostream>
#include <string>
#include"Header.h"

using namespace std;

void creditList(int *userNum) {
	cout << "1. Nhi Dinh" << endl;
	cout << "2. Haozhe Zhang" << endl;
	cout << "3. Jessie Huang" << endl;
	cout << "4. Teresa Cheung" << endl;
	cout << "5. James Boultinghouse" << endl;
	cout << "6. Thien Pham" << endl;
	*userNum = 0;
}

void userMenu(int* userNum) {

	while (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8))) {
		cout << "1. Add" << endl;
		cout << "2. Remove " << endl;
		cout << "3. Sort " << endl;
		cout << "4. Previous Searches" << endl;
		cout << "5. Search" << endl;
		cout << "6. Credits " << endl;
		cout << "7. Sort and Print " << endl;
		cout << "8. Quit " << endl;
		cout << endl;
		cout << "choice - ";
		cin >> *userNum;
		if (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8))) {

			cout << endl;
			cout << "Be serious." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			*userNum = 0;
			cout << endl;
		}
	}
}

void addition(int *userNum) {
	int chap = 0;
	string def = "?";
	string word = "?";
	cout << "Input your word: " << endl;
	cin >> word;
	cout << "Input the definition of this word: " << endl;
	cin.ignore();//Important!!!
	getline(cin, def);
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
}

void deletion(int *userNum) {
	string weebs;
	cout << "Which word do you want to remove?" << endl;
	cin >> weebs;

	//some searching and removing function here you are welcome
	*userNum = 0;
}

void sort(int *userNum) {
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
}

void search(int *userNum) {

}

void previous(int *userNum) {

}




int main() {
	int userInput;
	int* userNum = &userInput;


	do {
		userMenu(userNum);
		switch (*userNum) {
		case 1: {
			addition(userNum);
			break;
		}case 2: {
			deletion(userNum);
			break;
		}case 3: {
			sort(userNum);
			break;
		}case 4: {
			previous(userNum);
			*userNum = 0;
			break;
		}case 5: {
			search(userNum);
			*userNum = 0;
			break;
		}case 6: {
			creditList(userNum);
			*userNum = 0;
			break;
		}
		}userMenu(userNum);
	} while (*userNum != 8);

	return 0;
}




//#include<iostream>
//#include<string>
//#include <string.h>
//#include<stdexcept>
//#include <stdio.h>
//
//using namespace std;
//
//void userMenu(int *userNum);
//
//struct node
//{
//	string name;
//	node *next;
//};
//class list
//{
//private:
//	node * head, *tail;
//public:
//	list()
//	{
//		head = NULL;
//		tail = NULL;
//
//	}
//	void print() {
//		node *temp = new node;
//		temp = head;
//		int counter = 0;
//		while (temp != NULL) {
//			cout << temp->name << " ";
//			temp = temp->next;
//			counter++;
//			if (counter % 8 == 0) {
//				cout << endl;
//			}
//		}
//	}
//	void append1(string stuff) {//add one page to the linked list
//		node *temp = new node;
//		temp->name = stuff;
//		temp->next = head;
//		head = temp;
//	}
//	void insert(int position, string stuff) {//actually not insertion, this function replaces a designated node's value with the stuff string
//		node *current = head;
//		int i = 0;
//		while (i < position) {
//			current = current->next;
//			i++;
//		}
//		current->name = stuff;
//	}
//	bool checkexistence(string pagename) {//check if there is a node with such a name
//		node * temp = new node;
//		temp = head;
//		while (temp->next != NULL) {
//			if (temp->name == pagename) {
//				return true;
//			}
//			temp = temp->next;
//		}
//		return false;
//	}
//	void searchanddestroy(int* released, string pagename) {//replace the node(s) with the designated name with free node(s)
//		node * temp = new node;
//		temp = head;
//		*released = 0;
//		for (int i = 0; i < 32; i++) {
//			if (temp->name == pagename) {
//				temp->name = "Free";
//				(*released)++;
//			}
//			temp = temp->next;
//		}
//	}
//	int numFrags() {//return the number of fragments
//		node *temp = new node;
//		int counter = 0;
//		int agg = 0;
//		temp = head;
//		while (temp->next != NULL) {
//			while (temp->name == "Free") {
//				counter++;
//				if (temp->next != NULL) {
//					temp = temp->next;
//				}
//				else {
//					return agg + 1;
//				}
//			}
//			if (counter != 0)
//			{
//				agg += 1;
//			}
//			counter = 0;
//			temp = temp->next;
//			if ((temp->name == "Free") && (temp->next == NULL)) {
//				return agg + 1;
//			}
//		}
//		return agg;
//	}
//	bool hasSpace(int pages) {//check if the linked list can fit in this amount of pages
//		node * temp = new node;
//		node * current = new node;
//		node * test = new node;
//
//		current = head;
//		temp = current;
//		test = current;
//		int count = 0;
//		while (current->next != NULL) {
//			for (int i = 0; i < pages; i++) {
//				if (temp->name == "Free") {
//
//					if (count == pages) {
//						return true;
//					}
//					if (temp->next != NULL) {
//						temp = temp->next;
//						count++;
//					}
//				}
//				else {
//					count = 0;
//					i = pages;
//				}
//			}
//			current = current->next;
//			temp = current;
//			test = current;
//			for (int i = 0; i < pages; i++) {//test node checks if the distance from the current pointer to the end of the linkedlist is big enough.
//				test = test->next;
//			}
//			if (test == NULL) {
//				return false;
//			}
//		}
//		return false;
//	}
//	bool checkallfree() {//check if there are only free pages
//		node* temp = new node;
//		temp = head;
//		for (int i = 0; i < 32; i++) {
//			if (temp->name != "Free") {
//				return false;
//			}
//			temp = temp->next;
//		}
//		return true;
//	}
//	int findholesforworst(int pages) {//worst fit algorithm. it finds out the biggest hole and returns its position
//		int holeposition;
//		int biggesthole = 0;
//		node *temp = new node;
//		node *current = new node;
//		current = head;
//		temp = current;
//		int count = 0;
//		for (int i = 0; i < 32; i++) {
//			if (temp->name == "Free") {
//				while ((temp->next != NULL) && (temp->name == "Free")) {
//					count++;
//					temp = temp->next;
//				}
//				if (count > biggesthole) {
//					biggesthole = count;
//					holeposition = i;
//				}
//				count = 0;
//			}
//			current = current->next;
//			temp = current;
//		}
//
//		return holeposition;
//	}
//	int findholesforbest(int pages) {//best fit algorithm. it finds out the smallest hole the page(s) can fit in and returns its position
//		node *temp = new node;
//		temp = head;
//		int lastnonfree = 0;
//		int position = 0;
//		if (this->checkallfree()) {//If all free then return 0
//			return 0;
//		}
//		while (temp->next != NULL) {//Test out where the last non free node is
//			if ((temp->name != "Free") && (temp->next != NULL)) {
//				lastnonfree = position;
//			}
//			temp = temp->next;
//			position++;
//		}
//		temp = head;//Initialize the temp node
//
//		int smallesthole = 31 - lastnonfree;
//		int holeposition = lastnonfree + 1;//the next hole is located next to the last non free node
//		position = 0;
//
//		int count = 0;
//		bool firsttimeFree = false;
//		int firstfreeposition = 0;
//		while (temp != NULL) {
//			if (temp->name != "Free") {
//				if ((count >= pages) && (count < smallesthole)) {
//					smallesthole = count;
//					holeposition = firstfreeposition;
//					count = 0;
//				}
//				if (position == lastnonfree) {
//					return holeposition;
//				}
//			}
//			else {
//				if (!firsttimeFree) {
//					firsttimeFree = true;
//					firstfreeposition = position;
//				}
//				count++;
//			}
//			position++;
//			temp = temp->next;
//		}
//		return holeposition;
//	}
//};