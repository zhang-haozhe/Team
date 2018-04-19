#include"Header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

List::List() { this->head = NULL; }
static List definition; //all definitions
static List term; //all terms
static List number; //chapter and lesson index
static List memory; //stores searched terms from the user
static List numDef; //definitions with indexed chapters+lessons

//stores definitions by section
static List def01;
static List def02;
static List def03;
static List def04;
static List def05;
static List def06;
static List def07;
static List def09;
static List def10;
static List def11;



void List::addTerm(string term) {
    if (head == NULL) {
        head = new Node();
        head->value = term;
        size++;
        return;
    }

    Node * temp = head;
    while (temp->next != NULL) {
        temp = temp->next;

    }
    temp->next = new Node();
    temp->next->value = term;
    size++;
}
int List::deleteTerm(string term) {
    Node * temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->value == term) {
            temp->value = "Free";
            return index;
        }
        temp = temp->next;
        index++;
    }
    //Note: if term is not found, return -1, then where the method was called, if index = -1, then
    //term does not exist and don't do the other deletion method calls.
    return -1;
}
void List::deleteTermDetails(int index) {
    Node * temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->value = "";
}
void List::load(string fileName) {
    ifstream read;
    read.open(fileName);
    string line;

    while (getline(read, line)) {
        this->addTerm(line);
    }

    read.close();
}
Node* List::getHead() {
    return this->head;
}
int List::getSize() {
    return this->size;
}
bool List::contains(string term) {
    Node * temp = new Node;
    temp = head;
    while (temp != NULL) {
        if (temp->value == term) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void List::print() {
    Node *temp = new Node;
    temp = head;
    int counter = 0;
    string tempString;
    char tempChar;
    while (temp != NULL) {
        if (temp->value != "Free") {
            while (counter != temp->value.length()) {
                tempChar=temp->value.at(counter);
                if (temp->value.at(counter) == '[') {
                    cout << endl;
                }
                else if (temp->value.at(counter) == '@') {
                    tempString += "@";
                    //while ((temp->value.at(counter + 1) != ' ') && (counter + 1 != temp->value.length())) {
                    //  counter++;
                    // tempString += temp->value.at(counter);
                    //}
                    for (int i = 0; i < 5; i++) {

                        counter++;

                        tempString += temp->value.at(counter);

                    }
                    if (tempString == "@u00AC") { //negation
                        cout << "\u00AC";
                    }
                    else if (tempString == "@u2194") { //biconditional
                        cout << "\u2194";
                    }
                    else if (tempString == "@u2219") { //dot
                        cout << "\u2219";
                    }
                    else if (tempString == "@u220A") { //subset of (tiny curvy e)
                        cout << "\u220A";
                    }
                    else if (tempString == "@u2211") { //sigma
                        cout << "\u2211";
                    }
                    else if (tempString == "@u222a") { //union
                        cout << "\u222a";
                    }
                    else if (tempString == "@u2229") { //intersection
                        cout << "\u2229";
                    }
                    else if (tempString == "@u2295") {//exclusive or
                        cout << "\u2295";
                    }
                    else if (tempString == "@u2192") { //right arrow
                        cout << "\u2192";
                    }
                    else if (tempString == "@u2286") { // subset of
                        cout << "\u2286";
                    }
                    else if (tempString == "@u2261") { // equivalent (three lines)
                        cout << "\u2261";
                    }
                    else if (tempString == "@u2200") { // for all
                        cout << "\u2200";
                    }
                    else if (tempString == "@u2203") { // there exists
                        cout << "\u2203";
                    }
                    else if (tempString == "@u2081") { // subscript 1
                        cout << "\u2081";
                    }
                    else if (tempString == "@u2082") { // subscript 2
                        cout << "\u2082";
                    }
                    else if (tempString == "@u2099") { // subscript n
                        cout << "\u2099";
                    }
                    else if (tempString == "@u2308") { // left ceiling
                        cout << "\u2308";
                    }
                    else if (tempString == "@u2309") { // right ceiling
                        cout << "\u2309";
                    }
                    else if (tempString == "@u2260") { //not equal sign
                        cout << "\u2260";
                    }
                    tempString = "";
                }
                else {
                    cout << temp->value.at(counter);
                }
                counter++;
            }
        }
        temp = temp->next;
        counter = 0;
        cout << endl;
        //cout << endl;
    }
}
void List::insertAtBeginning(Node**start) {
    Node*temp = new Node;
    temp->value;
    temp->next = *start;
    *start = temp;
}
void List::bubbleSort(Node*start) {
    int swapped, i;
    Node *ptr = head;
    Node *temp = NULL;
    if (ptr == NULL) {
        return;
    }
    do {
        swapped = 0;
        ptr = start;
        while (ptr->next != temp) {
            if (ptr->value > ptr->next->value) {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        temp = ptr;
    } while (swapped);
}
void List::swap(Node*a, Node*b) {
    string temp = a->value;
    a->value = b->value;
    b->value = temp;
}
void List::printSearchDef(string term) {
    Node*current = this->head;
    string temp;
    int parenIdx;
    string printOut = "";
    string addTerm = "";
    while (current != NULL) {
        parenIdx = current->value.find_first_of(":");
        temp = current->value.substr(0, parenIdx);
        if (strToUpper(temp) == strToUpper(term)) {
            printOut = current->value;
            int counter = 0;
            string tempString = "";
            while (counter != current->value.length()) {
                if (current->value.at(counter) == '[') {
                    cout << endl;
                }
                else if (current->value.at(counter) == '@') {
                    tempString += "@";
                    for (int i = 0; i < 5; i++) {

                        counter++;

                        tempString += current->value.at(counter);

                    }
                    if (tempString == "@u00AC") { //negation
                        cout << "\u00AC";
                    }
                    else if (tempString == "@u2194") { //biconditional
                        cout << "\u2194";
                    }
                    else if (tempString == "@u2219") { //dot
                        cout << "\u2219";
                    }
                    else if (tempString == "@u220A") { //subset of (tiny curvy e)
                        cout << "\u220A";
                    }
                    else if (tempString == "@u2211") { //sigma
                        cout << "\u2211";
                    }
                    else if (tempString == "@u222a") { //union
                        cout << "\u222a";
                    }
                    else if (tempString == "@u2229") { //intersection
                        cout << "\u2229";
                    }
                    else if (tempString == "@u2295") {//exclusive or
                        cout << "\u2295";
                    }
                    else if (tempString == "@u2192") { //right arrow
                        cout << "\u2192";
                    }
                    else if (tempString == "@u2286") { // subset of
                        cout << "\u2286";
                    }
                    else if (tempString == "@u2261") { // equivalent (three lines)
                        cout << "\u2261";
                    }
                    else if (tempString == "@u2200") { // for all
                        cout << "\u2200";
                    }
                    else if (tempString == "@u2203") { // there exists
                        cout << "\u2203";
                    }
                    else if (tempString == "@u2081") { // subscript 1
                        cout << "\u2081";
                    }
                    else if (tempString == "@u2082") { // subscript 2
                        cout << "\u2082";
                    }
                    else if (tempString == "@u2099") { // subscript n
                        cout << "\u2099";
                    }
                    else if (tempString == "@u2308") { // left ceiling
                        cout << "\u2308";
                    }
                    else if (tempString == "@u2309") { // right ceiling
                        cout << "\u2309";
                    }
                    else if (tempString == "@u2260") { //not equal sign
                        cout << "\u2260";
                    }
                    else if (tempString == "@u0027") { //apostrophe
                        cout << "\u0027";
                    }
                    else if (tempString == "@u221A") { //root
                        cout << "\u221A";
                    }

                    tempString = "";
                }
                else {
                    cout << current->value.at(counter);
                }
                counter++;
            }
        }
        if (!memory.contains(term)) {
            addTerm = term;
            memory.addTerm(addTerm);
        }
        current = current->next;
    }
    if (printOut == "") {
        cout << term << " does not exist in this dictionary" << endl;
        if (!memory.contains(term)) {
            addTerm = term;
            memory.addTerm(addTerm);
        }
    }
}
string List::strToUpper(string str) {
    for (int i = 0; i < str.size(); i++) {
        str.at(i) = toupper(str.at(i));
    }
    return str;
}
string List::removeWhiteSpace(string term) {
    string newTerm = "";
    for (int i = 0; i < term.length(); i++) {
        if (term[i] != ' ') newTerm += term[i];
    }
    return newTerm;
}
void List::printMemory() {
    Node *temp = new Node;
    int newLine = 1;
    temp = head;
    string tempString;
    if (temp == NULL) {
        cout << "There's nothing in here..." << endl;
    }
    while (temp != NULL) {
        cout << temp->value << endl;
        temp = temp->next;
    }

}


void userMenu(int* userNum) {
    while (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8) || (*userNum == 9))) {
        cout << "\n-------------------------";
        cout << "\n        MAIN MENU";
        cout << "\n-------------------------\n";
        cout << "1. Search Term" << endl;
        cout << "2. Previous Searches" << endl;
        cout << "3. View Dictionary" << endl;
        cout << "4. Sort Dictionary" << endl;
        cout << "5. Table of Contents" << endl;
        cout << "6. About and Help" << endl;
        cout << "7. Credits" << endl;
        cout << "8. Quit" << endl;
        cout << endl;
        cout << "choice - ";
        cin >> *userNum;
        if (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8))) {
            cout << endl;
            cout << "Invalid Input." << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            *userNum = 0;
            cout << endl;
        }
    }
}
void sort(int *userNum) {
	int selection = 0;
	int numCh = 0;
	int numSec = 0;
	int subSelect = 0;

	cout << "\n------------------------------------------------------------------------------";
	cout << "\nSORT TERMS";
	cout << "\n------------------------------------------------------------------------------\n";
	cout << "Sort terms alphabetically and prints sorted terms out" << endl;
	cout << "\n1. Sort Sections" << endl;
	cout << "2. Sort Chapters" << endl;
	cout << "3. Sort Entire Dictionary" << endl;
	cout << "4. Go Back" << endl;
	cout << "\nchoice - ";
	cin >> selection;
	if (cin.fail() || (selection != 1) && (selection != 2) && (selection != 3) && (selection != 4)) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		*userNum = 4;
		cout << endl;
	}
	if (selection == 1) {
		cout << "Enter amount of sections to sort (maximum of 7) - ";
		cin >> numSec;
		if (cin.fail() || (numSec > 7) || (numSec < 1)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else {
			sortSec(numSec);
		}
		*userNum = 4;
	}
	if (selection == 2) {
		cout << "Enter amount of chapters to sort (maximum of 3) - ";
		cin >> numCh;
		if (cin.fail() || (numCh < 1)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else if (numCh > 3) {
			cout << "Invalid Input. You can only input up to 3 chapters" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else {
			sortChp(numCh);
		}
		*userNum = 4;
	}
	if (selection == 3) {
		cout << "1. Sort by Chapters" << endl;
		cout << "2. Sort All" << endl;
		cout << "3. Go Back" << endl;
		cout << "choice - ";
		cin >> subSelect;
		if (cin.fail() || !(subSelect >= 1 && subSelect <= 3)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
			*userNum = 4;
		}
		if (subSelect == 1 || subSelect == 2) {
			sortEntire(subSelect);
			*userNum == 4;
		}
		if (subSelect == 3) {
			*userNum = 4;
		}
	}
	if (selection == 4) {
		*userNum = 0;
	}
}
void sortSec(int numSec) {
	cout << "test" << endl;
}
void sortChp(int numChp) {
	List *chList = new List;
	Node *head1 = sort01.getHead();
	Node *head2 = sort02.getHead();
	Node *head3 = sort03.getHead();
	Node *head4 = sort04.getHead();
	Node *head5 = sort05.getHead();
	Node *head6 = sort06.getHead();
	Node *head7 = sort07.getHead();
	Node *head9 = sort09.getHead();
	Node *head10 = sort10.getHead();
	Node *head11 = sort11.getHead();

	if (numChp == 1) {
		cout << "Add Chapter - ";
		int ch1; cin >> ch1;
		cout << "\nSORTED CHAPTER " << ch1 << " PRINTED";
		cout << "\n------------------------------------------------------------------------------\n";
		if (ch1 == 1) {
			sort01.bubbleSort(head1);
			sort01.print();
		}
		else if (ch1 == 2) {
			sort02.bubbleSort(head2);
			sort02.print();
		}
		else if (ch1 == 3) {
			sort03.bubbleSort(head3);
			sort03.print();
		}
		else if (ch1 == 4) {
			sort04.bubbleSort(head4);
			sort04.print();
		}
		else if (ch1 == 5) {
			sort05.bubbleSort(head5);
			sort05.print();
		}
		else if (ch1 == 6) {
			sort06.bubbleSort(head6);
			sort06.print();
		}
		else if (ch1 == 7) {
			sort07.bubbleSort(head7);
			sort07.print();
		}
		else if (ch1 == 9) {
			sort09.bubbleSort(head9);
			sort09.print();
		}
		else if (ch1 == 10) {
			sort10.bubbleSort(head10);
			sort10.print();
		}
		else if (ch1 == 11) {
			sort11.bubbleSort(head11);
			sort11.print();
		}
	}
	else if (numChp == 2) {
		cout << "Add Chapter - ";
		int ch1; cin >> ch1;
		if (cin.fail() || !(ch1 >= 1 && ch1 <= 7) && !(ch1 >= 9 && ch1 <= 11)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else chList->addTerm(to_string(ch1));
		cout << "Add Chapter - ";
		int ch2; cin >> ch2;
		if (cin.fail() || !(ch2 >= 1 && ch2 <= 7) && !(ch2 >= 9 && ch2 <= 11)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (chList->contains(to_string(ch2))) {
			cout << "Duplicate" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else chList->addTerm(to_string(ch2));

		cout << "\nPrint selection? " << endl;
		cout << "1. Print Selected Chapters" << endl;
		cout << "2. Cancel" << endl;
		cout << "choice - ";
		int yn; cin >> yn;
		if (cin.fail() || (yn != 1) || (yn != 2)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (yn == 1) {
			if (chList->contains("1")) {
				sort01.bubbleSort(head1);
				cout << "\nSORTED CHAPTER 1 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort01.print();
			}
			if (chList->contains("2")) {
				sort02.bubbleSort(head2);
				cout << "\nSORTED CHAPTER 2 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort02.print();
			}
			if (chList->contains("3")) {
				sort03.bubbleSort(head3);
				cout << "\nSORTED CHAPTER 3 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort03.print();
			}
			if (chList->contains("4")) {
				sort04.bubbleSort(head4);
				cout << "\nSORTED CHAPTER 4 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort04.print();
			}
			if (chList->contains("5")) {
				sort05.bubbleSort(head5);
				cout << "\nSORTED CHAPTER 5 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort05.print();
			}
			if (chList->contains("6")) {
				sort06.bubbleSort(head6);
				cout << "\nSORTED CHAPTER 6 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort06.print();
			}
			if (chList->contains("7")) {
				cout << "\nSORTED CHAPTER 7 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort07.bubbleSort(head7);
				sort07.print();
			}
			if (chList->contains("9")) {
				cout << "\nSORTED CHAPTER 9 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort09.bubbleSort(head9);
				sort09.print();
			}
			if (chList->contains("10")) {
				cout << "\nSORTED CHAPTER 10 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort10.bubbleSort(head10);
				sort10.print();
			}
			if (chList->contains("11")) {
				cout << "\nSORTED CHAPTER 11 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort11.bubbleSort(head11);
				sort11.print();
			}
		}
		if (yn == 2) return;
	}
	else if (numChp == 3) {
		cout << "Add Chapter - ";
		int ch1; cin >> ch1;
		if (cin.fail() || !(ch1 >= 1 && ch1 <= 7) && !(ch1 >= 9 && ch1 <= 11)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else chList->addTerm(to_string(ch1));
		cout << "Add Chapter - ";
		int ch2; cin >> ch2;
		if (cin.fail() || !(ch2 >= 1 && ch2 <= 7) && !(ch2 >= 9 && ch2 <= 11)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (chList->contains(to_string(ch2))) {
			cout << "Duplicate" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else chList->addTerm(to_string(ch2));
		cout << "Add Chapter - ";
		int ch3; cin >> ch3;
		if (cin.fail() || !(ch3 >= 1 && ch3 <= 7) && !(ch3 >= 9 && ch3 <= 11)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (chList->contains(to_string(ch3))) {
			cout << "Duplicate" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else chList->addTerm(to_string(ch3));

		cout << "\nPrint selection? " << endl;
		cout << "1. Print Selected Chapters" << endl;
		cout << "2. Cancel" << endl;
		cout << "choice - ";
		int yn; cin >> yn;
		if (cin.fail() || (yn != 1) || (yn != 2)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (yn == 1) {
			if (chList->contains("1")) {
				sort01.bubbleSort(head1);
				cout << "\nSORTED CHAPTER 1 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort01.print();
			}
			if (chList->contains("2")) {
				sort02.bubbleSort(head2);
				cout << "\nSORTED CHAPTER 2 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort02.print();
			}
			if (chList->contains("3")) {
				sort03.bubbleSort(head3);
				cout << "\nSORTED CHAPTER 3 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort03.print();
			}
			if (chList->contains("4")) {
				sort04.bubbleSort(head4);
				cout << "\nSORTED CHAPTER 4 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort04.print();
			}
			if (chList->contains("5")) {
				sort05.bubbleSort(head5);
				cout << "\nSORTED CHAPTER 5 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort05.print();
			}
			if (chList->contains("6")) {
				sort06.bubbleSort(head6);
				cout << "\nSORTED CHAPTER 6 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort06.print();
			}
			if (chList->contains("7")) {
				cout << "\nSORTED CHAPTER 7 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort07.bubbleSort(head7);
				sort07.print();
			}
			if (chList->contains("9")) {
				cout << "\nSORTED CHAPTER 9 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort09.bubbleSort(head9);
				sort09.print();
			}
			if (chList->contains("10")) {
				cout << "\nSORTED CHAPTER 10 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort10.bubbleSort(head10);
				sort10.print();
			}
			if (chList->contains("11")) {
				cout << "\nSORTED CHAPTER 11 PRINTED";
				cout << "\n------------------------------------------------------------------------------\n";
				sort11.bubbleSort(head11);
				sort11.print();
			}
		}
		if (yn == 2) return;
	}
}
void sortEntire(int sub) {
	//Linked list declarations here
	List *sortAll = new List;

	if (sub == 1) {
		//FIXME: sort by chapter
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 1 - THE FOUNDATIONS: LOGIC AND PROOFS";
		cout << "\n------------------------------------------------------------------------------\n";
		Node *head1 = sort01.getHead();
		sort01.bubbleSort(head1);
		sort01.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 2";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head2 = sort02.getHead();
		sort02.bubbleSort(head2);
		sort02.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 3";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head3 = sort03.getHead();
		sort03.bubbleSort(head3);
		sort03.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 4";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head4 = sort04.getHead();
		//sort04.bubbleSort(head4);
		//sort04.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 5";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head5 = sort05.getHead();
		sort05.bubbleSort(head5);
		sort05.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 6";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head6 = sort06.getHead();
		sort06.bubbleSort(head6);
		sort06.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 7";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head7 = sort07.getHead();
		sort07.bubbleSort(head7);
		sort07.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 9";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head9 = sort09.getHead();
		sort09.bubbleSort(head9);
		sort09.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 10";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head10 = sort10.getHead();
		sort10.bubbleSort(head10);
		sort10.print();
		cout << "\n------------------------------------------------------------------------------\n";
		cout << "CHAPTER 11";
		cout << "\n------------------------------------------------------------------------------\n";
		Node*head11 = sort11.getHead();
		sort11.bubbleSort(head11);
		sort11.print();
	}
	else if (sub == 2) {
		//FIXME: sort everything
		sortAll->load("allDefinitions.txt");
		Node *head = sortAll->getHead();
		sortAll->bubbleSort(head);
		sortAll->print();
	}
}
void search(int *userNum) {
    cout << "\n------------------------------";
    cout << "\n         SEARCH TERM";
    cout << "\n------------------------------";
    cout << "\n1. Search Entire Dictionary";
    cout << "\n2. Search by Chapter";
    cout << "\n3. Go Back";
    cout << "\n\nchoice - ";
    int select; cin >> select;
    if (cin.fail() || (select != 1) && (select != 2) && (select != 3)) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        *userNum = 1;
    }
    if (select == 1) {
        cin.clear();
        cin.ignore(1024, '\n');
        cout << "\nEnter term - ";
        string inTerm;
        getline(cin, inTerm);
        definition.printSearchDef(inTerm);
        cout << "\n\nPress enter to continue...";
        cin.clear();
        cin.ignore(1024, '\n');
        *userNum = 1;
    }
    if (select == 2) {
        cout << "Enter Chapter Number - ";
        int chIn; cin >> chIn;
        if (cin.fail() || !(chIn >= 1 && chIn <= 7) && !(chIn >= 9 && chIn <= 11)) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << endl;
        }
        else {
            searchByCh(chIn);
            cout << "\n\nPress enter to continue...";
            cin.clear();
            cin.ignore(1024, '\n');
        }
        *userNum = 1;
    }
    if (select == 3) {
        *userNum = 0;
    }
}
void searchByCh(int chIn) {
    cin.clear();
    cin.ignore(1024, '\n');
    cout << "\nEnter term: ";
    string searchTerm;
    getline(cin, searchTerm);
    if (chIn == 1) def01.printSearchDef(searchTerm);
    if (chIn == 2) def02.printSearchDef(searchTerm);
    if (chIn == 3) def03.printSearchDef(searchTerm);
    if (chIn == 4) def04.printSearchDef(searchTerm);
    if (chIn == 5) def05.printSearchDef(searchTerm);
    if (chIn == 6) def06.printSearchDef(searchTerm);
    if (chIn == 7) def07.printSearchDef(searchTerm);
    if (chIn == 9) def09.printSearchDef(searchTerm);
    if (chIn == 10) def10.printSearchDef(searchTerm);
    if (chIn == 11) def11.printSearchDef(searchTerm);
}

void view(int *userNum) {
    int VDSelection = 0;
    int chIn = 0;
    int VDnumSec = 0;
    cout << "\n---------------------------------------------------";
    cout << "\n                VIEW DICTIONARY";
    cout << "\n---------------------------------------------------\n";
    cout << "1. View Individual Section" << endl;
    cout << "2. View Individual Chapter" << endl;
    cout << "3. View Selection of Sections" << endl;
    cout << "4. View Selection of Chapters" << endl;
    cout << "5. View Entire Dictionary" << endl;
    cout << "6. Go Back" << endl;
    cout << "\nchoice - ";
    cin >> VDSelection;
    if (cin.fail() || (VDSelection != 1) && (VDSelection != 2) && (VDSelection != 3) && (VDSelection != 4) && (VDSelection != 5) && (VDSelection != 6)) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        *userNum = 3;
        cout << endl;
    }
    if (VDSelection == 1) {
        //cout << "Enter the section number: " << endl;
        //cin >> VDnumSec;
        viewBySection();
        *userNum = 3;
    }
    if (VDSelection == 2) {
        viewByCh();
        *userNum = 3;
    }
    if (VDSelection == 3) {
        cout << "Input which sections you want to view. " << endl;
        cout << "Note: You can only view up to 5 chapters at a time.\n";
        //FIXME: some method calling shit that asks what sections the user wants to view
        //max of 5 sections at a time because ain't nobody got the time or motivation to write 7+ nested loops
        *userNum = 3;
    }
    if (VDSelection == 4) {
        cout << "Input which chapters you want to view. " << endl;
        cout << "Note: You can only view up to 3 chapters at a time.\n";
        viewSelCh();
        *userNum = 3;
    }
    if (VDSelection == 5) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nUF COT3100 SPRING 2018 - IMPORTANT TERMS";
        cout << "\n------------------------------------------------------------------------------\n";
        def01.print();
        def02.print();
        def03.print();
        def04.print();
        def05.print();
        def06.print();
        def07.print();
        def09.print();
        def10.print();
        def11.print();
        //print to console but chapter 4 needs to be fixed, also fix formatting, it's ugly
        //definition.print();
        *userNum = 3;
    }
    if (VDSelection == 6) {
        *userNum = 0;
    }
}
void viewBySection() {
    string inSec;
    int chp;
    cout << "\nEnter the chapter number: ";
    cin >> chp;
    if ((chp >= 1 && chp <= 7) || (chp >= 9 && chp <= 11)) {
        cout << "\nEnter the section number for chapter " << chp << ": ";
        int section; cin >> section;
        if (chp == 1) {
            if (section >= 1 && section <= 8) {
                inSec = "01" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 1\n";
        }
        if (chp == 2) {
            if ((section >= 1 && section <= 4) || section == 6) {
                inSec = "02" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chpater 2\n";
        }
        if (chp == 3) {
            if (section >= 1 && section <= 3) {
                inSec = "03" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 3\n";
        }
        if (chp == 4) {
            if (section >= 1 && section <= 3) {
                inSec = "04" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 4\n";
        }
        if (chp == 5) {
            if (section >= 1 && section <= 3) {
                inSec = "05" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 5\n";
        }
        if (chp == 6) {
            if (section >= 1 && section <= 3) {
                inSec = "06" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does exist in Chapter 6\n";
        }
        if (chp == 7) {
            if (section >= 1 && section <= 3) {
                inSec = "07" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 7\n";
        }
        if (chp == 9) {
            if (section == 1 || section == 3 || section == 5) {
                inSec = "09" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 9\n";
        }
        if (chp == 10) {
            if (section >= 1 && section <= 8) {
                inSec = "10" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 10\n";
        }
        if (chp == 11) {
            if (section >= 1 && section <= 5) {
                inSec = "11" + section;
                //numDef.printSection(inSec);
                cout << endl;
            }
            else cout << "\nThis section does not exist in Chapter 11\n";
        }
    }
    else cout << "\nInvalid Input";
}
void viewByCh() {
    cout << "Input the chapter number:" << endl;
    int chIn; cin >> chIn;
    if (chIn == 1) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 1 - THE FOUNDATIONS: LOGIC AND PROOFS";
        cout << "\n------------------------------------------------------------------------------\n";
        def01.print();
    }
    else if (chIn == 2) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 2 - BASIC STRUCTURES: SETS, FUNCTIONS, SEQUENCES";
        cout << "\n------------------------------------------------------------------------------\n";
        def02.print();
    }
    else if (chIn == 3) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 3 - ALGORITHMS";
        cout << "\n------------------------------------------------------------------------------\n";
        def03.print();
    }
    else if (chIn == 4) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 4 - NUMBER THEORY AND CRYPTOLOGY";
        cout << "\n------------------------------------------------------------------------------\n";
        //cout << "\nchapter 4 faulty asf, pls fix\n";
        def04.print();
    }
    else if (chIn == 5) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 5 - INDUCTION AND RECURSION";
        cout << "\n------------------------------------------------------------------------------\n";
        def05.print();
    }
    else if (chIn == 6) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 6 - COUNTING";
        cout << "\n------------------------------------------------------------------------------\n";
        def06.print();
    }
    else if (chIn == 7) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 7 - DISCRETE PROBABILITY";
        cout << "\n------------------------------------------------------------------------------\n";
        def07.print();
    }
    else if (chIn == 9) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 9 - RELATIONS";
        cout << "\n------------------------------------------------------------------------------\n";
        def09.print();
    }
    else if (chIn == 10) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 10 - GRAPHS";
        cout << "\n------------------------------------------------------------------------------\n";
        def10.print();
    }
    else if (chIn == 11) {
        cout << "\n------------------------------------------------------------------------------";
        cout << "\nCHAPTER 11 - TREES";
        cout << "\n------------------------------------------------------------------------------\n";
        def11.print();
    }
    else {
        cout << "Chapter does not exist";
    }
}
void viewSelCh() {
    List *chList = new List;
    cout << "\n1. Add Chapter";
    cout << "\n2. Go Back";
    cout << "\n\nchoice - ";
    int choice1; cin >> choice1;
    if (cin.fail() || (choice1 != 1) && (choice1 != 2)) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(1024, '\n');
        cout << endl;
    }
    if (choice1 == 1) {
        cout << "\nEnter chapter number: ";
        int ch1; cin >> ch1;
        if (cin.fail() || !(ch1 >= 1 && ch1 <= 7) && !(ch1 >= 9 && ch1 <= 11)) {
            cout << "Invalid input." << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cout << endl;
        }
        else {
            chList->addTerm(to_string(ch1));
            cout << "\n1. Add Another Chapter";
            cout << "\n2. View Chapter " << ch1;
            cout << "\n3. Go back";
            cout << "\n\nchoice - ";
            int in2;
            int *choice2 = &in2; cin >> in2;
            if (cin.fail() || (*choice2 != 1) && (*choice2 != 2) && (*choice2 != 3)) {
                cout << "Invalid input." << endl;
                cin.clear();
                cin.ignore(1024, '\n');
                cout << endl;
            }
            if (*choice2 == 1) {
                cout << "\nEnter chapter number: ";
                int ch2; cin >> ch2;
                if (cin.fail() || !(ch1 >= 1 && ch1 <= 7) && !(ch1 >= 9 && ch1 <= 11)) {
                    cout << "Invalid input." << endl;
                    cin.clear();
                    cin.ignore(1024, '\n');
                    cout << endl;
                }
                else if (chList->contains(to_string(ch2))) {
                    cout << "\nChapter already added" << endl;
                    choice1 = 1;
                }
                else {
                    chList->addTerm(to_string(ch2));
                    cout << "\n1. Add Another Chapter and Print";
                    cout << "\n2. View Chapters " << ch1 << " and " << ch2;
                    cout << "\n3. Go back";
                    cout << "\n\nchoice - ";
                    int choice3; cin >> choice3;
                    if (cin.fail() || (choice3 != 1) && (choice3 != 2) && (choice3 != 3)) {
                        cout << "Invalid input." << endl;
                        cin.clear();
                        cin.ignore(1024, '\n');
                        cout << endl;
                    }
                    if (choice3 == 1) {
                        cout << "\nEnter chapter number: ";
                        int ch3; cin >> ch3;
                        if (cin.fail() || !(ch3 >= 1 && ch3 <= 7) && !(ch3 >= 9 && ch3 <= 11)) {
                            cout << "Invalid input." << endl;
                            cin.clear();
                            cin.ignore(1024, '\n');
                            cout << endl;
                        }
                        else if (chList->contains(to_string(ch3))) {
                            cout << "\nChapter already added" << endl;
                            choice3 = 1;
                        }
                        else {
                            chList->addTerm(to_string(ch3));
                            cout << "\nPRINTING OUT CHAPTERS " << ch1 << ", " << ch2 << ", AND " << ch3 << endl;
                            cout << "--------------------------------------------------------------------------------" << endl;
                            if (chList->contains("1")) def01.print();
                            if (chList->contains("2")) def02.print();
                            if (chList->contains("3")) def03.print();
                            if (chList->contains("4")) def04.print();
                            if (chList->contains("5")) def05.print();
                            if (chList->contains("6")) def06.print();
                            if (chList->contains("7")) def07.print();
                            if (chList->contains("9")) def09.print();
                            if (chList->contains("10")) def10.print();
                            if (chList->contains("11")) def11.print();
                        }
                    }
                    if (choice3 == 2) {
                        cout << "\nPRINTING OUT CHAPTERS " << ch1 << " AND " << ch2 << endl;
                        cout << "--------------------------------------------------------------------------------" << endl;
                        if (chList->contains("1")) def01.print();
                        if (chList->contains("2")) def02.print();
                        if (chList->contains("3")) def03.print();
                        if (chList->contains("4")) def04.print();
                        if (chList->contains("5")) def05.print();
                        if (chList->contains("6")) def06.print();
                        if (chList->contains("7")) def07.print();
                        if (chList->contains("9")) def09.print();
                        if (chList->contains("10")) def10.print();
                        if (chList->contains("11")) def11.print();
                    }
                    if (choice3 == 3) return;
                }
            }
            if (*choice2 == 2) {
                cout << "\nPRINTING OUT CHAPTER " << ch1 << endl;
                cout << "--------------------------------------------------------------------------------" << endl;
                if (chList->contains("1")) def01.print();
                if (chList->contains("2")) def02.print();
                if (chList->contains("3")) def03.print();
                if (chList->contains("4")) def04.print();
                if (chList->contains("5")) def05.print();
                if (chList->contains("6")) def06.print();
                if (chList->contains("7")) def07.print();
                if (chList->contains("9")) def09.print();
                if (chList->contains("10")) def10.print();
                if (chList->contains("11")) def11.print();
            }
            if (*choice2 == 3) return;
        }
    }
    if (choice1 == 2) return;
}

void previous(int *userNum) {
    //DONE
    cout << "\n---------------------------------------------------";
    cout << "\n                PREVIOUS SEARCHES";
    cout << "\n---------------------------------------------------\n";
    memory.printMemory();
    *userNum = 0;
}
void toc(int *userNum) {
    //DONE
    cout << "\n---------------------------------------------------";
    cout << "\n                 TABLE OF CONTENTS";
    cout << "\n---------------------------------------------------\n";
    cout << "1. The Foundations: Logic and Proofs" << endl;
    cout << "\t Section 1.1: Propositional Logic" << endl;
    cout << "\t Section 1.2: Applications of Propositional Logic" << endl;
    cout << "\t Section 1.3: Propositional Equivalences" << endl;
    cout << "\t Section 1.4: Predicates and Quantifiers" << endl;
    cout << "\t Section 1.5: Nested Quantifiers" << endl;
    cout << "\t Section 1.6: Rules of Inference" << endl;
    cout << "\t Section 1.7: Introduction to Proofs" << endl;
    cout << "\t Section 1.8: Proof Methods and Strategy" << endl;
    cout << endl;
    cout << "2. Basic Structures: Sets, Functions, Sequences, Sums, and Matrices" << endl;
    cout << "\t Section 2.1: Sets" << endl;
    cout << "\t Section 2.2: Set Operations" << endl;
    cout << "\t Section 2.3: Functions" << endl;
    cout << "\t Section 2.4: Sequences and Summations" << endl;
    cout << "\t Section 2.6: Matrices" << endl;
    cout << endl;
    cout << "3. Algorithms" << endl;
    cout << "\t Section 3.1: Algorithms" << endl;
    cout << "\t Section 3.2: The Growth of Functions" << endl;
    cout << "\t Section 3.3: Complexity of Algorithms" << endl;
    cout << endl;
    cout << "4. Number Theory and Cryptography" << endl;
    cout << "\t Section 4.1: Divisibility and Modular Arithmetic" << endl;
    cout << "\t Section 4.2: Integer Representations and Algorithms" << endl;
    cout << "\t Section 4.3: Primes and Greatest Common Divisors" << endl;
    cout << endl;
    cout << "5. Induction and Recursion" << endl;
    cout << "\t Section 5.1: Mathematical Induction" << endl;
    cout << "\t Section 5.2: Strong Induction and Well Ordering" << endl;
    cout << "\t Section 5.3: Recursive Definitions and Structural Induction" << endl;
    cout << endl;
    cout << "6. Counting" << endl;
    cout << "\t Section 6.1: The Basics of Counting" << endl;
    cout << "\t Section 6.2: The Pigeonhole Principle" << endl;
    cout << "\t Section 6.3: Permutations and Combinations" << endl;
    cout << endl;
    cout << "7. Discrete Probability" << endl;
    cout << "\t Section 7.1: An Introduction to Discrete Probability" << endl;
    cout << "\t Section 7.2: Probability Theory" << endl;
    cout << "\t Section 7.3: Bayes' Theorem" << endl;
    cout << endl;
    cout << "9. Relations" << endl;
    cout << "\t Section 9.1: Relations and their Properties" << endl;
    cout << "\t Section 9.3: Representing Relations" << endl;
    cout << "\t Section 9.5: Equivalence Relations" << endl;
    cout << endl;
    cout << "10. Graphs" << endl;
    cout << "\t Section 10.1 & 10.2: Graphs and Graph Models, Graph Terminology and Special Types of Graphs" << endl;
    cout << "\t Section 10.3: Representing Graphs and Graph Isomorphism" << endl;
    cout << "\t Section 10.4: Connectivity" << endl;
    cout << endl;
    cout << "11. Trees" << endl;
    cout << "\t Section 11.1: Introduction to Trees" << endl;
    cout << "\t Section 11.2: Application of Trees" << endl;
    cout << "\t Section 11.3: Tree Traversal" << endl;
    cout << "\t Section 11.4: Spanning Trees" << endl;
    cout << endl;
    cout << "NOTE: Chapter 8 not covered in Spring 2018" << endl;
    cout << endl;
    *userNum = 0;
}
void help(int*userNum) {
    cout << "\n---------------------------------------------------";
    cout << "\n                 ABOUT AND HELP";
    cout << "\n---------------------------------------------------\n";
    cout << "1. Search Term: searches for a term that is inputted by the user." << endl;
    cout << "2. Previous Searches: when selected, a list of terms that were previously searched for will be displayed." << endl;
    cout << "3. Sort Dictionary: sorts the words in the dictionary by chapters, sections or entire dictionary - determined by user input." << endl;
    cout << "4. View Dictionary: prints dictionary by chapter, a selection of chapters, section, a selection of sections or entire dictionary. " << endl;
    cout << "5. Modifiable Dictionary: Sort by chapters, sections, or the entire dictionary." << endl;
    cout << "6. Table of Contents: prints out a list of chapters and their respective sections in the textbook." << endl;
    cout << "7. Navigation Help: prints out a help menu navigating through the user menu." << endl;
    cout << "8. Credits: prints out the students working on this project and references" << endl;
    cout << "9. Quit: exits the program." << endl;
    *userNum = 0;
}
void creditList(int *userNum) {
    cout << "\n------------------------------";
    cout << "\n           CREDITS";
    cout << "\n------------------------------";
    cout << "\nCONTRIBUTORS" << endl;
    cout << "1. Nhi Dinh" << endl;
    cout << "2. Haozhe Zhang" << endl;
    cout << "3. Jessie Huang" << endl;
    cout << "4. Teresa Cheung" << endl;
    cout << "5. James Boultinghouse" << endl;
    cout << "6. Thien Pham" << endl;
    *userNum = 0;
}

int main() {
    int userInput;
    int* userNum = &userInput;

    definition.load("allDefinitions.txt");
    term.load("allTerms.txt");
    number.load("numbers.txt");
    numDef.load("numAllDef.txt");

    def01.load("1Def.txt");
    def02.load("2Def.txt");
    def03.load("3Def.txt");
    def04.load("4Def.txt");
    def05.load("5Def.txt");
    def06.load("6Def.txt");
    def07.load("7Def.txt");
    def09.load("9Def.txt");
    def10.load("10Def.txt");
    def11.load("11Def.txt");
    
    sort01.load("1Def.txt");
	sort02.load("2Def.txt");
	sort03.load("3Def.txt");
	sort04.load("4Def.txt");
	sort05.load("5Def.txt");
	sort06.load("6Def.txt");
	sort07.load("7Def.txt");
	sort09.load("9Def.txt");
	sort10.load("10Def.txt");
	sort11.load("11Def.txt");

    do {
        userMenu(userNum);
        switch (*userNum) {
            case 1: {
                search(userNum);
                break;
            }case 2: {
                previous(userNum);
                break;
            }case 3: {
                view(userNum);
                break;
            }case 4: {
                sort(userNum);
                break;
            }case 5: {
                toc(userNum);
                break;
            }case 6: {
                help(userNum);
                break;
            }case 7: {
                creditList(userNum);
                cout << endl;
                break;
            }
        }userMenu(userNum);
    } while (*userNum != 8);

    return 0;
}
