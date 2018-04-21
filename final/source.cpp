#include"header.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

List::List() { this->head = NULL; }
static List definition; //all definitions
static List memory; //stores searched terms from user
static List sectionIdList; //list of all section indexes
static List sortSecSel; //list of words in selection of sections to sort

//stores definitions by chapter
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

//definitions by section
static List sec11;
static List sec12;
static List sec13;
static List sec14;
static List sec15;
static List sec16;
static List sec17;
static List sec21;
static List sec22;
static List sec23;
static List sec24;
static List sec26;
static List sec31;
static List sec32;
static List sec33;
static List sec41;
static List sec42;
static List sec43;
static List sec45;
static List sec46;
static List sec51;
static List sec52;
static List sec53;
static List sec61;
static List sec62;
static List sec63;
static List sec65;
static List sec71;
static List sec72;
static List sec73;
static List sec91;
static List sec92;
static List sec93;
static List sec101;
static List sec102;
static List sec103;
static List sec104;
static List sec105;
static List sec106;
static List sec107;
static List sec108;
static List sec111;
static List sec112;
static List sec113;
static List sec114;
static List sec115;

//stores sorted definitions by chapter
static List sort01;
static List sort02;
static List sort03;
static List sort04;
static List sort05;
static List sort06;
static List sort07;
static List sort09;
static List sort10;
static List sort11;
//sort sections
static List sort011;
static List sort012;
static List sort013;
static List sort014;
static List sort015;
static List sort016;
static List sort017;
static List sort021;
static List sort022;
static List sort023;
static List sort024;
static List sort026;
static List sort031;
static List sort032;
static List sort033;
static List sort041;
static List sort042;
static List sort043;
static List sort045;
static List sort046;
static List sort051;
static List sort052;
static List sort053;
static List sort061;
static List sort062;
static List sort063;
static List sort065;
static List sort071;
static List sort072;
static List sort073;
static List sort091;
static List sort092;
static List sort093;
static List sort101;
static List sort102;
static List sort103;
static List sort104;
static List sort105;
static List sort106;
static List sort107;
static List sort108;
static List sort111;
static List sort112;
static List sort113;
static List sort114;
static List sort115;

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
    while (temp != NULL) {
        if (temp->value != "Free") {
            while (counter != temp->value.length()) {
                if (temp->value.at(counter) == '[') {
                    cout << endl;
                }
                else if (temp->value.at(counter) == '@') {
                    tempString += "@";
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
		    else if (tempString == "@u208B") { // subscript -
                        cout << "\u208B";
                    }
		    else if (tempString == "@u208A") { // subscript +
                        cout << "\u208A";
                    }
		    else if (tempString == "@u2080") { // subscript 0
                        cout << "\u2080";
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
                    else if (tempString == "@u221A") { //square root sign
                        cout << "\u221A";
                    }
                    else if (tempString == "@u2C7C") { //subscript j
                        cout << "\u2C7C";
                    }
		    else if (tempString == "@u2096") { //subscript k
                        cout << "\u2096";
                    }
                    else if (tempString == "@u2098") { //subscript m
                        cout << "\u2098";
                    }
                    else if (tempString == "@u1d62") { //subscript i
                        cout << "\u1d62";
                    }
                    else if (tempString == "@u005b") { //open bracket
                        cout<< "\u005b";
                    }
			else if (tempString == "@u00D7") { //multiplication mark
                        cout<< "\u00D7";
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
        cout << endl;
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
                    while ((current->value.at(counter + 1) != ' ') && (counter + 1 != current->value.length())) {
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
		    else if (tempString == "@u208B") { // subscript -
                        cout << "\u208B";
                    }
		    else if (tempString == "@u208A") { // subscript +
                        cout << "\u208A";
                    }
		    else if (tempString == "@u2080") { // subscript 0
                        cout << "\u2080";
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
                    else if (tempString == "@u221A") { //square root sign
                        cout << "\u221A";
                    }
                    else if (tempString == "@u2C7C") { //subscript j
                        cout << "\u2C7C";
                    }
		    else if (tempString == "@u2096") { //subscript k
                        cout << "\u2096";
                    }
                    else if (tempString == "@u2098") { //subscript m
                        cout << "\u2098";
                    }
                    else if (tempString == "@u1d62") { //subscript i
                        cout << "\u1d62";
                    }
                    else if (tempString == "@u005b") { //open bracket
                        cout<< "\u005b";
                    }
			else if (tempString == "@u00D7") { //multiplication mark
                        cout<< "\u00D7";
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
		cout << "Enter amount of sections to sort (maximum of 6) - ";
		cin >> numSec;
		if (cin.fail() || (numSec > 6) || (numSec < 1)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else {
			sortSections(numSec);
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
			*userNum = 4;
		}
		if (subSelect == 3) {
			*userNum = 4;
		}
	}
	if (selection == 4) {
		*userNum = 0;
	}
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
		sortAll->load("allDef.txt");
		Node *head = sortAll->getHead();
		sortAll->bubbleSort(head);
		sortAll->print();
	}
}
void sortSections(int numSec) {
	//max of 6 sections to sort
	if (numSec == 1) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			int sel = sortPrint();
			if (sel == 1 || sel == 2) {
				cout << "Section Sorted!" << endl;
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "PRINTING OUT SORTED SECTION" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				sortPrintSecIdv(sec1);
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
	}
	if (numSec == 2) {
		List *secList = new List;
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			cout << "1st Section Sorted!" << endl;
			secList->addTerm(sec1);
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Sorted!" << endl;
				secList->addTerm(sec2);
			}
			else if (sec2 == sec1) {
				cout << "Duplicate" << endl;
				if (reenter()) sortSections(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) sortSections(numSec);
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
		int sel = sortPrint();
		if (sel == 1) {
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SORTED SECTIONS INDIVIDUALLY" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				sortPrintSecIdv(secId);
				head = head->next;
			}
		}
		if (sel == 2) {
			//FIXME: print out stuff in sortedSecSel list
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SORTED TERMS OF ALL SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				addSortSel(secId);
				head = head->next;
			}
			sortedSecSel.bubbleSort(sortedSecSel.getHead());
			sortedSecSel.print();
		}
	}
	if (numSec == 3) {
		List *secList = new List;
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			cout << "1st Section Sorted!" << endl;
			secList->addTerm(sec1);
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Sorted!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Sorted!" << endl;
					secList->addTerm(sec3);
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) sortSections(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) sortSections(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) sortSections(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) sortSections(numSec);
			}
			int sel = sortPrint();
			if (sel == 1) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED SECTIONS INDIVIDUALLY" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					sortPrintSecIdv(secId);
					head = head->next;
				}
			}
			if (sel == 2) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED TERMS OF ALL SELECTED SECTIONS" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					addSortSel(secId);
					head = head->next;
				}
				sortedSecSel.bubbleSort(sortedSecSel.getHead());
				sortedSecSel.print();
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
	}
	if (numSec == 4) {
		List *secList = new List;
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Sorted!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Sorted!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Sorted!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Sorted!" << endl;
						secList->addTerm(sec4);
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) sortSections(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) sortSections(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) sortSections(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) sortSections(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) sortSections(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) sortSections(numSec);
			}
			int sel = sortPrint();
			if (sel == 1) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED SECTIONS INDIVIDUALLY" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					sortPrintSecIdv(secId);
					head = head->next;
				}
			}
			if (sel == 2) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED TERMS OF ALL SELECTED SECTIONS" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					addSortSel(secId);
					head = head->next;
				}
				sortedSecSel.bubbleSort(sortedSecSel.getHead());
				sortedSecSel.print();
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
	}
	if (numSec == 5) {
		List *secList = new List;
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Sorted!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Sorted!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Sorted!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Sorted!" << endl;
						secList->addTerm(sec4);
						string sec5 = sectionId();
						if (sectionIdList.contains(sec5) && !secList->contains(sec5)) {
							cout << "5th Section Sorted!" << endl;
							secList->addTerm(sec5);
						}
						else if (secList->contains(sec5)) {
							cout << "Duplicate" << endl;
							if (reenter()) sortSections(numSec);
						}
						else {
							cout << "This section does not exist" << endl;
							if (reenter()) sortSections(numSec);
						}
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) sortSections(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) sortSections(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) sortSections(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) sortSections(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) sortSections(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) sortSections(numSec);
			}
			int sel = sortPrint();
			if (sel == 1) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED SECTIONS INDIVIDUALLY" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					sortPrintSecIdv(secId);
					head = head->next;
				}
			}
			if (sel == 2) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED TERMS OF ALL SELECTED SECTIONS" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					addSortSel(secId);
					head = head->next;
				}
				sortedSecSel.bubbleSort(sortedSecSel.getHead());
				sortedSecSel.print();
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
	}
	if (numSec == 6) {
		List *secList = new List;
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Sorted!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Sorted!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Sorted!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Sorted!" << endl;
						secList->addTerm(sec4);
						string sec5 = sectionId();
						if (sectionIdList.contains(sec5) && !secList->contains(sec5)) {
							cout << "5th Section Sorted!" << endl;
							secList->addTerm(sec5);
							string sec6 = sectionId();
							if (sectionIdList.contains(sec6) && !secList->contains(sec6)) {
								cout << "6th Section Sorted!" << endl;
								secList->addTerm(sec6);
							}
							else if (secList->contains(sec6)) {
								cout << "Duplicate" << endl;
								if (reenter()) sortSections(numSec);
							}
							else {
								cout << "This section does not exist" << endl;
								if (reenter()) sortSections(numSec);
							}
						}
						else if (secList->contains(sec5)) {
							cout << "Duplicate" << endl;
							if (reenter()) sortSections(numSec);
						}
						else {
							cout << "This section does not exist" << endl;
							if (reenter()) sortSections(numSec);
						}
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) sortSections(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) sortSections(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) sortSections(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) sortSections(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) sortSections(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) sortSections(numSec);
			}
			int sel = sortPrint();
			if (sel == 1) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED SECTIONS INDIVIDUALLY" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					sortPrintSecIdv(secId);
					head = head->next;
				}
			}
			if (sel == 2) {
				string secId;
				Node*head = secList->getHead();
				cout << "\n--------------------------------------------------------------------------------" << endl;
				cout << "\nPRINTING OUT SORTED TERMS OF ALL SELECTED SECTIONS" << endl;
				cout << "--------------------------------------------------------------------------------" << endl;
				while (head != NULL) {
					secId = head->value;
					addSortSel(secId);
					head = head->next;
				}
				sortedSecSel.bubbleSort(sortedSecSel.getHead());
				sortedSecSel.print();
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) sortSections(numSec);
		}
	}
	sortedSecSel.clear();
}
void sortPrintSecIdv(string sec) {
	string chNum = sec.substr(0, 2);
	char secNum = sec.at(2);
	if (chNum == "01") {
		if (secNum == '1') {
			cout << "\nSECTION 1.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort011.bubbleSort(sort011.getHead());
			sort011.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 1.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort012.bubbleSort(sort012.getHead());
			sort012.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 1.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort013.bubbleSort(sort013.getHead());
			sort013.print();
		}
		if (secNum == '4') {
			cout << "\nSECTION 1.4" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort014.bubbleSort(sort014.getHead());
			sort014.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 1.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort015.bubbleSort(sort015.getHead());
			sort015.print();
		}
		if (secNum == '6') {
			cout << "\nSECTION 1.6" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort016.bubbleSort(sort016.getHead());
			sort016.print();
		}
		if (secNum == '7') {
			cout << "\nSECTION 1.7" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort017.bubbleSort(sort017.getHead());
			sort017.print();
		}
	}
	if (chNum == "02") {
		if (secNum == '1') {
			cout << "\nSECTION 2.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort021.bubbleSort(sort021.getHead());
			sort021.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 2.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort022.bubbleSort(sort022.getHead());
			sort022.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 2.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort023.bubbleSort(sort023.getHead());
			sort023.print();
		}
		if (secNum == '4') {
			cout << "\nSECTION 2.4" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort024.bubbleSort(sort024.getHead());
			sort024.print();
		}
		if (secNum == '6') {
			cout << "\nSECTION 2.6" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort026.bubbleSort(sort026.getHead());
			sort026.print();
		}
	}
	if (chNum == "03") {
		if (secNum == '1') {
			cout << "\nSECTION 3.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort031.bubbleSort(sort031.getHead());
			sort031.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 3.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort032.bubbleSort(sort032.getHead());
			sort032.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 3.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort033.bubbleSort(sort033.getHead());
			sort033.print();
		}
	}
	if (chNum == "04") {
		if (secNum == '1') {
			cout << "\nSECTION 4.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort041.bubbleSort(sort041.getHead());
			sort041.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 4.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort042.bubbleSort(sort042.getHead());
			sort042.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 4.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort043.bubbleSort(sort043.getHead());
			sort043.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 4.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort045.bubbleSort(sort045.getHead());
			sort045.print();
		}
		if (secNum == '6') {
			cout << "\nSECTION 4.6" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort046.bubbleSort(sort046.getHead());
			sort046.print();
		}
	}
	if (chNum == "05") {
		if (secNum == '1') {
			cout << "\nSECTION 5.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort051.bubbleSort(sort051.getHead());
			sort051.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 5.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort052.bubbleSort(sort052.getHead());
			sort052.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 5.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort053.bubbleSort(sort053.getHead());
			sort053.print();
		}
	}
	if (chNum == "06") {
		if (secNum == '1') {
			cout << "\nSECTION 6.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort061.bubbleSort(sort061.getHead());
			sort061.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 6.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort062.bubbleSort(sort062.getHead());
			sort062.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 6.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort063.bubbleSort(sort063.getHead());
			sort063.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 6.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort065.bubbleSort(sort065.getHead());
			sort065.print();
		}
	}
	if (chNum == "07") {
		if (secNum == '1') {
			cout << "\nSECTION 7.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort071.bubbleSort(sort071.getHead());
			sort071.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 7.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort072.bubbleSort(sort072.getHead());
			sort072.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 7.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort073.bubbleSort(sort073.getHead());
			sort073.print();
		}
	}
	if (chNum == "09") {
		if (secNum == '1') {
			cout << "\nSECTION 9.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort091.bubbleSort(sort091.getHead());
			sort091.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 9.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort092.bubbleSort(sort092.getHead());
			sort092.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 9.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort093.bubbleSort(sort093.getHead());
			sort093.print();
		}
	}
	if (chNum == "10") {
		if (secNum == '1') {
			cout << "\nSECTION 10.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort101.bubbleSort(sort101.getHead());
			sort101.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 10.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort102.bubbleSort(sort102.getHead());
			sort102.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 10.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort103.bubbleSort(sort103.getHead());
			sort103.print();
		}
		if (secNum == '4') {
			cout << "\nSECTION 10.4" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort104.bubbleSort(sort104.getHead());
			sort104.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 10.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort105.bubbleSort(sort105.getHead());
			sort105.print();
		}
		if (secNum == '6') {
			cout << "\nSECTION 10.6" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort106.bubbleSort(sort106.getHead());
			sort106.print();
		}
		if (secNum == '7') {
			cout << "\nSECTION 10.7" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort107.bubbleSort(sort107.getHead());
			sort107.print();
		}
	}
	if (chNum == "11") {
		if (secNum == '1') {
			cout << "\nSECTION 11.1" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort111.bubbleSort(sort111.getHead());
			sort111.print();
		}
		if (secNum == '2') {
			cout << "\nSECTION 11.2" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort112.bubbleSort(sort112.getHead());
			sort112.print();
		}
		if (secNum == '3') {
			cout << "\nSECTION 11.3" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort113.bubbleSort(sort113.getHead());
			sort113.print();
		}
		if (secNum == '4') {
			cout << "\nSECTION 11.4" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort114.bubbleSort(sort114.getHead());
			sort114.print();
		}
		if (secNum == '5') {
			cout << "\nSECTION 11.5" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			sort115.bubbleSort(sort115.getHead());
			sort115.print();
		}
	}
}
void addSortSel(string sec) {
	string chNum = sec.substr(0, 2);
	char secNum = sec.at(2);
	if (chNum == "01") {
		if (secNum == '1') {
			Node*h011 = sort011.getHead();
			while (h011 != NULL) {
				sortedSecSel.addTerm(h011->value);
				h011 = h011->next;
			}
		}
		if (secNum == '2') {
			Node*h012 = sort012.getHead();
			while (h012 != NULL) {
				sortedSecSel.addTerm(h012->value);
				h012 = h012->next;
			}
		}
		if (secNum == '3') {
			Node*h013 = sort013.getHead();
			while (h013 != NULL) {
				sortedSecSel.addTerm(h013->value);
				h013 = h013->next;
			}
		}
		if (secNum == '4') {
			Node*h014 = sort014.getHead();
			while (h014 != NULL) {
				sortedSecSel.addTerm(h014->value);
				h014 = h014->next;
			}
		}
		if (secNum == '5') {
			Node*h015 = sort015.getHead();
			while (h015 != NULL) {
				sortedSecSel.addTerm(h015->value);
				h015 = h015->next;
			}
		}
		if (secNum == '6') {
			Node*h016 = sort016.getHead();
			while (h016 != NULL) {
				sortedSecSel.addTerm(h016->value);
				h016 = h016->next;
			}
		}
		if (secNum == '7') {
			Node*h017 = sort017.getHead();
			while (h017 != NULL) {
				sortedSecSel.addTerm(h017->value);
				h017 = h017->next;
			}
		}
	}
	if (chNum == "02") {
		if (secNum == '1') {
			Node*h021 = sort021.getHead();
			while (h021 != NULL) {
				sortedSecSel.addTerm(h021->value);
				h021 = h021->next;
			}
		}
		if (secNum == '2') {
			Node*h022 = sort022.getHead();
			while (h022 != NULL) {
				sortedSecSel.addTerm(h022->value);
				h022 = h022->next;
			}
		}
		if (secNum == '3') {
			Node*h023 = sort023.getHead();
			while (h023 != NULL) {
				sortedSecSel.addTerm(h023->value);
				h023 = h023->next;
			}
		}
		if (secNum == '4') {
			Node*h024 = sort024.getHead();
			while (h024 != NULL) {
				sortedSecSel.addTerm(h024->value);
				h024 = h024->next;
			}
		}
		if (secNum == '6') {
			Node*h026 = sort026.getHead();
			while (h026 != NULL) {
				sortedSecSel.addTerm(h026->value);
				h026 = h026->next;
			}
		}
	}
	if (chNum == "03") {
		if (secNum == '1') {
			Node*h031 = sort031.getHead();
			while (h031 != NULL) {
				sortedSecSel.addTerm(h031->value);
				h031 = h031->next;
			}
		}
		if (secNum == '2') {
			Node*h032 = sort032.getHead();
			while (h032 != NULL) {
				sortedSecSel.addTerm(h032->value);
				h032 = h032->next;
			}
		}
		if (secNum == '3') {
			Node*h033 = sort033.getHead();
			while (h033 != NULL) {
				sortedSecSel.addTerm(h033->value);
				h033 = h033->next;
			}
		}
	}
	if (chNum == "04") {
		if (secNum == '1') {
			Node*h041 = sort041.getHead();
			while (h041 != NULL) {
				sortedSecSel.addTerm(h041->value);
				h041 = h041->next;
			}
		}
		if (secNum == '2') {
			Node*h042 = sort042.getHead();
			while (h042 != NULL) {
				sortedSecSel.addTerm(h042->value);
				h042 = h042->next;
			}
		}
		if (secNum == '3') {
			Node*h043 = sort043.getHead();
			while (h043 != NULL) {
				sortedSecSel.addTerm(h043->value);
				h043 = h043->next;
			}
		}
		if (secNum == '5') {
			Node*h045 = sort045.getHead();
			while (h045 != NULL) {
				sortedSecSel.addTerm(h045->value);
				h045 = h045->next;
			}
		}
		if (secNum == '6') {
			Node*h046 = sort046.getHead();
			while (h046 != NULL) {
				sortedSecSel.addTerm(h046->value);
				h046 = h046->next;
			}
		}
	}
	if (chNum == "05") {
		if (secNum == '1') {
			Node*h051 = sort051.getHead();
			while (h051 != NULL) {
				sortedSecSel.addTerm(h051->value);
				h051 = h051->next;
			}
		}
		if (secNum == '2') {
			Node*h052 = sort052.getHead();
			while (h052 != NULL) {
				sortedSecSel.addTerm(h052->value);
				h052 = h052->next;
			}
		}
		if (secNum == '3') {
			Node*h053 = sort053.getHead();
			while (h053 != NULL) {
				sortedSecSel.addTerm(h053->value);
				h053 = h053->next;
			}
		}
	}
	if (chNum == "06") {
		if (secNum == '1') {
			Node*h061 = sort061.getHead();
			while (h061 != NULL) {
				sortedSecSel.addTerm(h061->value);
				h061 = h061->next;
			}
		}
		if (secNum == '2') {
			Node*h062 = sort062.getHead();
			while (h062 != NULL) {
				sortedSecSel.addTerm(h062->value);
				h062 = h062->next;
			}
		}
		if (secNum == '3') {
			Node*h063 = sort063.getHead();
			while (h063 != NULL) {
				sortedSecSel.addTerm(h063->value);
				h063 = h063->next;
			}
		}
		if (secNum == '5') {
			Node*h065 = sort065.getHead();
			while (h065 != NULL) {
				sortedSecSel.addTerm(h065->value);
				h065 = h065->next;
			}
		}
	}
	if (chNum == "07") {
		if (secNum == '1') {
			Node*h071 = sort071.getHead();
			while (h071 != NULL) {
				sortedSecSel.addTerm(h071->value);
				h071 = h071->next;
			}
		}
		if (secNum == '2') {
			Node*h072 = sort072.getHead();
			while (h072 != NULL) {
				sortedSecSel.addTerm(h072->value);
				h072 = h072->next;
			}
		}
		if (secNum == '3') {
			Node*h073 = sort073.getHead();
			while (h073 != NULL) {
				sortedSecSel.addTerm(h073->value);
				h073 = h073->next;
			}
		}
	}
	if (chNum == "09") {
		if (secNum == '1') {
			Node*h091 = sort091.getHead();
			while (h091 != NULL) {
				sortedSecSel.addTerm(h091->value);
				h091 = h091->next;
			}
		}
		if (secNum == '3') {
			Node*h092 = sort092.getHead();
			while (h092 != NULL) {
				sortedSecSel.addTerm(h092->value);
				h092 = h092->next;
			}
		}
		if (secNum == '5') {
			Node*h093 = sort093.getHead();
			while (h093 != NULL) {
				sortedSecSel.addTerm(h093->value);
				h093 = h093->next;
			}
		}
	}
	if (chNum == "10") {
		if (secNum == '1') {
			Node*h101 = sort101.getHead();
			while (h101 != NULL) {
				sortedSecSel.addTerm(h101->value);
				h101 = h101->next;
			}
		}
		if (secNum == '2') {
			Node*h102 = sort102.getHead();
			while (h102 != NULL) {
				sortedSecSel.addTerm(h102->value);
				h102 = h102->next;
			}
		}
		if (secNum == '3') {
			Node*h103 = sort103.getHead();
			while (h103 != NULL) {
				sortedSecSel.addTerm(h103->value);
				h103 = h103->next;
			}
		}
		if (secNum == '4') {
			Node*h104 = sort104.getHead();
			while (h104 != NULL) {
				sortedSecSel.addTerm(h104->value);
				h104 = h104->next;
			}
		}
		if (secNum == '5') {
			Node*h105 = sort105.getHead();
			while (h105 != NULL) {
				sortedSecSel.addTerm(h105->value);
				h105 = h105->next;
			}
		}
		if (secNum == '6') {
			Node*h106 = sort106.getHead();
			while (h106 != NULL) {
				sortedSecSel.addTerm(h106->value);
				h106 = h106->next;
			}
		}
		if (secNum == '7') {
			Node*h107 = sort107.getHead();
			while (h107 != NULL) {
				sortedSecSel.addTerm(h107->value);
				h107 = h107->next;
			}
		}
		if (secNum == '8') {
			Node*h108 = sort108.getHead();
			while (h108 != NULL) {
				sortedSecSel.addTerm(h108->value);
				h108 = h108->next;
			}
		}
	}
	if (chNum == "11") {
		if (secNum == '1') {
			Node*h111 = sort111.getHead();
			while (h111 != NULL) {
				sortedSecSel.addTerm(h111->value);
				h111 = h111->next;
			}
		}
		if (secNum == '2') {
			Node*h112 = sort112.getHead();
			while (h112 != NULL) {
				sortedSecSel.addTerm(h112->value);
				h112 = h112->next;
			}
		}
		if (secNum == '3') {
			Node*h113 = sort113.getHead();
			while (h113 != NULL) {
				sortedSecSel.addTerm(h113->value);
				h113 = h113->next;
			}
		}
		if (secNum == '4') {
			Node*h114 = sort114.getHead();
			while (h114 != NULL) {
				sortedSecSel.addTerm(h114->value);
				h114 = h114->next;
			}
		}
		if (secNum == '5') {
			Node*h115 = sort115.getHead();
			while (h115 != NULL) {
				sortedSecSel.addTerm(h115->value);
				h115 = h115->next;
			}
		}
	}
}
int sortPrint() {
	cout << "\nPrint selection? " << endl;
	cout << "1. Print Sorted Sections Individually" << endl;
	cout << "2. Print Sorted Sections All Together" << endl;
	cout << "3. Cancel" << endl;
	cout << "choice - ";
	int yn; cin >> yn;
	if (cin.fail() || (yn != 1) && (yn != 2)) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		return 0;
	}
	if (yn == 1) {
		return 1;
	}
	if (yn == 2) {
		return 2;
	}
	if (yn == 3) {
		return 0;
	}
}
void List::clear() {
	Node*temp = new Node;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
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
        viewBySection();
        *userNum = 3;
    }
    if (VDSelection == 2) {
        viewByCh();
        *userNum = 3;
    }
    if (VDSelection == 3) {
        cout << "Input which sections you want to view. " << endl;
		cout << "Note: You can only view up to 6 chapters at a time in this menu.\n";
		int numSec;
		cout << "\nEnter the number of sections to view: " << endl;
		cin >> numSec;
		if (cin.fail() || numSec < 0) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		if (numSec > 6) {
			cout << "Too many sections! You can only input up to 6 sections" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
		}
		else viewSelSec(numSec);
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
        definition.print();
        *userNum = 3;
    }
    if (VDSelection == 6) {
        *userNum = 0;
    }
}
void viewBySection() {
    cout << "Input the chapter number:" << endl;
    int chp; cin >> chp;
    
    cout << "\nEnter the section number (1-7) for chapter " << chp << ": ";
    int section; cin >> section;
    if (chp == 1) {
        if (section == 1) {
            sec11.print();
        }
        else if (section == 2) {
            sec12.print();
        }
        else if (section == 3) {
            sec13.print();
        }
        else if (section == 4) {
            sec14.print();
        }
        else if (section == 5) {
            sec15.print();
        }
        else if (section == 6) {
            sec16.print();
        }
        else if (section == 7) {
            sec17.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 2) {
        if (section == 1) {
            sec21.print();
        }
        else if (section == 2) {
            sec22.print();
        }
        else if (section == 3) {
            sec23.print();
        }
        else if (section == 4) {
            sec24.print();
        }
        else if (section == 6) {
            sec26.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 3) {
        if (section == 1) {
            sec31.print();
        }
        else if (section == 2) {
            sec32.print();
        }
        else if (section == 3) {
            sec33.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 4) {
        if (section == 1) {
            sec41.print();
        }
        else if (section == 2) {
            sec42.print();
        }
        else if (section == 3) {
            sec43.print();
        }
        else if (section == 5) {
            sec45.print();
        }
        else if (section == 6) {
            sec46.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 5) {
        if (section == 1) {
            sec51.print();
        }
        else if (section == 2) {
            sec52.print();
        }
        else if (section == 3) {
            sec53.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 6) {
        if (section == 1) {
            sec61.print();
        }
        else if (section == 2) {
            sec62.print();
        }
        else if (section == 3) {
            sec63.print();
        }
        else if (section == 5) {
            sec65.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 7) {
        if (section == 1) {
			sec71.print();
		}
		else if (section == 2) {
			sec72.print();
		}
		else if (section == 3) {
			sec73.print();
		}
		else {
			cout << "Section does not exist." << endl;
		}
    }
    else if (chp == 9) {
        if (section == 1) {
			sec91.print();
		}
		else if (section == 2) {
			sec92.print();
		}
		else if (section == 3) {
			sec93.print();
		}
		else {
			cout << "Section does not exist." << endl;
		}
    }
    else if (chp == 10) {
 	if (section == 1) {
            sec101.print();
        }
        else if (section == 2) {
            sec102.print();
        }
        else if (section == 3) {
            sec103.print();
        }
        else if (section == 4) {
            sec104.print();
        }
        else if (section == 5) {
            sec105.print();
        }
        else if (section == 6) {
            sec106.print();
        }
        else if (section == 7) {
            sec107.print();
        }
        else if (section == 8) {
            sec108.print();
        }
        else {
            cout << "Section does not exist." << endl;
        }
    }
    else if (chp == 11) {
	    if (section == 1) {
			sec111.print();
		}
		else if (section == 2) {
			sec112.print();
		}
		else if (section == 3) {
			sec113.print();
		}
		else if (section == 3) {
			sec114.print();
		}
		else if (section == 3) {
			sec115.print();
		}
		else {
			cout << "Section does not exist." << endl;
		}
    }
    else {
        cout << "Chapter does not exist";
    }
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
void viewSelSec(int numSec) {
	List *secList = new List; //max size = 6
	if (numSec == 1) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTION" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			viewPrintSec(sec1);
		}
		else { 
			cout << "This section does not exist" << endl; 
			if (reenter()) viewSelSec(numSec);
		}
	}
	if (numSec == 2) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			cout << "1st Section Added!" << endl;
			secList->addTerm(sec1);
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Added!" << endl;
				secList->addTerm(sec2);
			}
			else if (sec2 == sec1) { 
				cout << "Duplicate" << endl; 
				if (reenter()) viewSelSec(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				viewPrintSec(secId);
				head = head->next;
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) viewSelSec(numSec);
		}
	}
	if (numSec == 3) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			cout << "1st Section Added!" << endl;
			secList->addTerm(sec1);
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Added!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Added!" << endl;
					secList->addTerm(sec3);
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) viewSelSec(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) viewSelSec(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				viewPrintSec(secId);
				head = head->next;
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) viewSelSec(numSec);
		}
	}
	if (numSec == 4) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Added!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Added!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Added!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Added!" << endl;
						secList->addTerm(sec4);
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) viewSelSec(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) viewSelSec(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) viewSelSec(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) viewSelSec(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				viewPrintSec(secId);
				head = head->next;
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) viewSelSec(numSec);
		}
	}
	if (numSec == 5) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Added!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Added!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Added!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Added!" << endl;
						secList->addTerm(sec4);
						string sec5 = sectionId();
						if (sectionIdList.contains(sec5) && !secList->contains(sec5)) {
							cout << "5th Section Added!" << endl;
							secList->addTerm(sec5);
						}
						else if (secList->contains(sec5)) {
							cout << "Duplicate" << endl;
							if (reenter()) viewSelSec(numSec);
						}
						else {
							cout << "This section does not exist" << endl;
							if (reenter()) viewSelSec(numSec);
						}
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) viewSelSec(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) viewSelSec(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) viewSelSec(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) viewSelSec(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				viewPrintSec(secId);
				head = head->next;
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) viewSelSec(numSec);
		}
	}
	if (numSec == 6) {
		string sec1 = sectionId();
		if (sectionIdList.contains(sec1)) {
			secList->addTerm(sec1);
			cout << "1st Section Added!" << endl;
			string sec2 = sectionId();
			if (sectionIdList.contains(sec2) && !secList->contains(sec2)) {
				cout << "2nd Section Added!" << endl;
				secList->addTerm(sec2);
				string sec3 = sectionId();
				if (sectionIdList.contains(sec3) && !secList->contains(sec3)) {
					cout << "3rd Section Added!" << endl;
					secList->addTerm(sec3);
					string sec4 = sectionId();
					if (sectionIdList.contains(sec4) && !secList->contains(sec4)) {
						cout << "4th Section Added!" << endl;
						secList->addTerm(sec4);
						string sec5 = sectionId();
						if (sectionIdList.contains(sec5) && !secList->contains(sec5)) {
							cout << "5th Section Added!" << endl;
							secList->addTerm(sec5);
							string sec6 = sectionId();
							if (sectionIdList.contains(sec6) && !secList->contains(sec6)) {
								cout << "6th Section Added!" << endl;
								secList->addTerm(sec6);
							}
							else if (secList->contains(sec6)) {
								cout << "Duplicate" << endl;
								if (reenter()) viewSelSec(numSec);
							}
							else {
								cout << "This section does not exist" << endl;
								if (reenter()) viewSelSec(numSec);
							}
						}
						else if (secList->contains(sec5)) {
							cout << "Duplicate" << endl;
							if (reenter()) viewSelSec(numSec);
						}
						else {
							cout << "This section does not exist" << endl;
							if (reenter()) viewSelSec(numSec);
						}
					}
					else if (secList->contains(sec4)) {
						cout << "Duplicate" << endl;
						if (reenter()) viewSelSec(numSec);
					}
					else {
						cout << "This section does not exist" << endl;
						if (reenter()) viewSelSec(numSec);
					}
				}
				else if (secList->contains(sec3)) {
					cout << "Duplicate" << endl;
					if (reenter()) viewSelSec(numSec);
				}
				else {
					cout << "This section does not exist" << endl;
					if (reenter()) viewSelSec(numSec);
				}
			}
			else if (secList->contains(sec2)) {
				cout << "Duplicate" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			else {
				cout << "This section does not exist" << endl;
				if (reenter()) viewSelSec(numSec);
			}
			string secId;
			Node*head = secList->getHead();
			cout << "\n--------------------------------------------------------------------------------" << endl;
			cout << "\nPRINTING OUT SELECTED SECTIONS" << endl;
			cout << "--------------------------------------------------------------------------------" << endl;
			while (head != NULL) {
				secId = head->value;
				viewPrintSec(secId);
				head = head->next;
			}
		}
		else {
			cout << "This section does not exist" << endl;
			if (reenter()) viewSelSec(numSec);
		}
	}
}
void viewPrintSec(string sec) {
	string chNum = sec.substr(0, 2);
	char secNum = sec.at(2);
	if (chNum == "01") {
		if (secNum == '1') sec11.print();
		if (secNum == '2') sec12.print();
		if (secNum == '3') sec13.print();
		if (secNum == '4') sec14.print();
		if (secNum == '5') sec15.print();
		if (secNum == '6') sec16.print();
		if (secNum == '7') sec17.print();
	}
	if (chNum == "02") {
		if (secNum == '1') sec21.print();
		if (secNum == '2') sec22.print();
		if (secNum == '3') sec23.print();
		if (secNum == '4') sec24.print();
		if (secNum == '6') sec26.print();
	}
	if (chNum == "03") {
		if (secNum == '1') sec31.print();
		if (secNum == '2') sec32.print();
		if (secNum == '3') sec33.print();
	}
	if (chNum == "04") {
		if (secNum == '1') sec41.print();
		if (secNum == '2') sec42.print();
		if (secNum == '3') sec43.print();
		if (secNum == '5') sec45.print();
		if (secNum == '6') sec46.print();
	}
	if (chNum == "05") {
		if (secNum == '1') sec51.print();
		if (secNum == '2') sec52.print();
		if (secNum == '3') sec53.print();
	}
	if (chNum == "06") {
		if (secNum == '1') sec61.print();
		if (secNum == '2') sec62.print();
		if (secNum == '3') sec63.print();
		if (secNum == '5') sec65.print();
	}
	if (chNum == "07") {
		if (secNum == '1') sec71.print();
		if (secNum == '2') sec72.print();
		if (secNum == '3') sec73.print();
	}
	if (chNum == "09") {
		if (secNum == '1') sec91.print();
		if (secNum == '3') sec92.print();
		if (secNum == '5') sec93.print();
	}
	if (chNum == "10") {
		if (secNum == '1') sec101.print();
		if (secNum == '2') sec102.print();
		if (secNum == '3') sec103.print();
		if (secNum == '4') sec104.print();
		if (secNum == '5') sec105.print();
		if (secNum == '6') sec106.print();
		if (secNum == '7') sec107.print();
		if (secNum == '8') sec108.print();
	}
	if (chNum == "11") {
		if (secNum == '1') sec111.print();
		if (secNum == '2') sec112.print();
		if (secNum == '3') sec113.print();
		if (secNum == '4') sec114.print();
		if (secNum == '5') sec115.print();
	}
}

void previous(int *userNum) {
    cout << "\n---------------------------------------------------";
    cout << "\n                PREVIOUS SEARCHES";
    cout << "\n---------------------------------------------------\n";
    memory.printMemory();
    *userNum = 0;
}
void toc(int *userNum) {
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
void listSections() {
	//chapter 1
	sectionIdList.addTerm("011");
	sectionIdList.addTerm("012");
	sectionIdList.addTerm("013");
	sectionIdList.addTerm("014");
	sectionIdList.addTerm("015");
	sectionIdList.addTerm("016");
	sectionIdList.addTerm("017");
	//chapter 2
	sectionIdList.addTerm("021");
	sectionIdList.addTerm("022");
	sectionIdList.addTerm("023");
	sectionIdList.addTerm("024");
	sectionIdList.addTerm("026");
	//chapter 3
	sectionIdList.addTerm("031");
	sectionIdList.addTerm("032");
	sectionIdList.addTerm("033");
	//chapter 4
	sectionIdList.addTerm("041");
	sectionIdList.addTerm("042");
	sectionIdList.addTerm("043");
	sectionIdList.addTerm("045");
	sectionIdList.addTerm("046");
	//chapter 5
	sectionIdList.addTerm("051");
	sectionIdList.addTerm("052");
	sectionIdList.addTerm("053");
	//chapter 6
	sectionIdList.addTerm("061");
	sectionIdList.addTerm("062");
	sectionIdList.addTerm("063");
	sectionIdList.addTerm("065");
	//chapter 7
	sectionIdList.addTerm("071");
	sectionIdList.addTerm("072");
	sectionIdList.addTerm("073");
	//chapter 9
	sectionIdList.addTerm("091");
	sectionIdList.addTerm("093");
	sectionIdList.addTerm("095");
	//chapter 10
	sectionIdList.addTerm("101");
	sectionIdList.addTerm("102");
	sectionIdList.addTerm("103");
	sectionIdList.addTerm("104");
	sectionIdList.addTerm("105");
	sectionIdList.addTerm("106");
	sectionIdList.addTerm("107");
	sectionIdList.addTerm("108");
	//chapter 11
	sectionIdList.addTerm("111");
	sectionIdList.addTerm("112");
	sectionIdList.addTerm("113");
	sectionIdList.addTerm("114");
	sectionIdList.addTerm("115");
}
string sectionId() {
	string idnum;
	cout << "\nEnter Chapter - ";
	int ch1; cin >> ch1;
	if (cin.fail() || !(ch1 >= 1 && ch1 <= 7) && !(ch1 >= 9 && ch1 <= 11)) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}
	cout << "Enter Section Number - ";
	int sec; cin >> sec;
	if (cin.fail()) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
	}
	else {
		if (ch1 == 1) idnum = "01" + to_string(sec);
		else if (ch1 == 2) idnum = "02" + to_string(sec);
		else if (ch1 == 3) idnum = "03" + to_string(sec);
		else if (ch1 == 4) idnum = "04" + to_string(sec);
		else if (ch1 == 5) idnum = "05" + to_string(sec);
		else if (ch1 == 6) idnum = "06" + to_string(sec);
		else if (ch1 == 7) idnum = "07" + to_string(sec);
		else if (ch1 == 9) idnum = "09" + to_string(sec);
		else if (ch1 == 10) idnum = "10" + to_string(sec);
		else if (ch1 == 11) idnum = "11" + to_string(sec);
	}
	return idnum;
}
bool reenter() {
	cout << "\nWould you like to re-enter your selection?" << endl;
	cout << "1. YES" << endl;
	cout << "2. NO" << endl;
	int in; cin >> in;
	if (cin.fail() || (in != 1) && (in != 2)) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		return false;
	}
	if (in == 1) {
		return true;
	}
	if (in == 2) {
		return false;
	}
}

int main() {
    int userInput;
    int* userNum = &userInput;
    
    definition.load("allDef.txt");
    listSections();
    //load non sorting chapters
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
    
    //load non sorting sections
    sec11.load("sec11.txt");
    sec12.load("sec12.txt");
    sec13.load("sec13.txt");
    sec14.load("sec14.txt");
    sec15.load("sec15.txt");
    sec16.load("sec16.txt");
    sec17.load("sec17.txt");
    sec21.load("sec21.txt");
    sec22.load("sec22.txt");
    sec23.load("sec23.txt");
    sec24.load("sec24.txt");
    sec26.load("sec26.txt");
    sec31.load("sec31.txt");
    sec32.load("sec32.txt");
    sec33.load("sec33.txt");
    sec41.load("sec41.txt");
    sec42.load("sec42.txt");
    sec43.load("sec43.txt");
    sec45.load("sec45.txt");
    sec46.load("sec46.txt");
    sec51.load("sec51.txt");
    sec52.load("sec52.txt");
    sec53.load("sec53.txt");
    sec61.load("sec61.txt");
    sec62.load("sec62.txt");
    sec63.load("sec63.txt");
    sec65.load("sec65.txt");
    sec71.load("sec71.txt");
    sec72.load("sec72.txt");
    sec73.load("sec73.txt");
    sec91.load("sec91.txt");
    sec92.load("sec92.txt");
    sec93.load("sec93.txt");
    sec101.load("sec101.txt");
    sec102.load("sec102.txt");
    sec103.load("sec103.txt");
    sec104.load("sec104.txt");
    sec105.load("sec105.txt");
    sec106.load("sec106.txt");
    sec107.load("sec107.txt");
    sec108.load("sec108.txt");
    sec111.load("sec111.txt");
    sec112.load("sec112.txt");
    sec113.load("sec113.txt");
    sec114.load("sec114.txt");
    sec115.load("sec115.txt");

    //load sorting definitions
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
    //load sorting sections	
    sort011.load("sec11.txt");
    sort012.load("sec12.txt");
    sort013.load("sec13.txt");
    sort014.load("sec14.txt");
    sort015.load("sec15.txt");
    sort016.load("sec16.txt");
    sort017.load("sec17.txt");
    sort021.load("sec21.txt");
    sort022.load("sec22.txt");
    sort023.load("sec23.txt");
    sort024.load("sec24.txt");
    sort026.load("sec26.txt");
    sort031.load("sec31.txt");
    sort032.load("sec32.txt");
    sort033.load("sec33.txt");
    sort041.load("sec41.txt");
    sort042.load("sec42.txt");
    sort043.load("sec43.txt");
    sort045.load("sec45.txt");
    sort046.load("sec46.txt");
    sort051.load("sec51.txt");
    sort052.load("sec52.txt");
    sort053.load("sec53.txt");
    sort061.load("sec61.txt");
    sort062.load("sec62.txt");
    sort063.load("sec63.txt");
    sort065.load("sec65.txt");
    sort071.load("sec71.txt");
    sort072.load("sec72.txt");
    sort073.load("sec73.txt");
    sort091.load("sec91.txt");
    sort092.load("sec92.txt");
    sort093.load("sec93.txt");
    sort101.load("sec101.txt");
    sort102.load("sec102.txt");
    sort103.load("sec103.txt");
    sort104.load("sec104.txt");
    sort105.load("sec105.txt");
    sort106.load("sec106.txt");
    sort107.load("sec107.txt");
    sort108.load("sec108.txt");
    sort111.load("sec111.txt");
    sort112.load("sec112.txt");
    sort113.load("sec113.txt");
    sort114.load("sec114.txt");
    sort115.load("sec115.txt");	
	
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

