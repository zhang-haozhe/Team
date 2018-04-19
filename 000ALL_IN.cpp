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
bool List::checkexistence(string term) {//check if there is a node with such a name
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
					while ((temp->value.at(counter + 1) != ' ') && (counter + 1 != temp->value.length())) {
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
bool List::search(Node*head, string term) {
	Node*current = head;
	//int compareStr;
	while (current != NULL) {
		string currUpper = strToUpper(current->value);
		string termUpper = strToUpper(term);
		if (removeWhiteSpace(currUpper) == termUpper) {
			return true;
		}
		current = current->next;
	}
	return false;
}
void List::printSearch(string term) {
	string addTerm;
	if (search(this->head, term)) {
		cout << term << endl;
		if (!memory.checkexistence(term)) {
			addTerm = term;
			memory.addTerm(addTerm);
		}
	}
	else {
		cout << term << " does not exist in this dictionary" << endl;
		if (!memory.checkexistence(term)) {
			addTerm = term;
			memory.addTerm(addTerm);
		}
	}
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
					cout << current->value.at(counter);
				}
				counter++;
			}
		}
		if (!memory.checkexistence(term)) {
			addTerm = term;
			memory.addTerm(addTerm);
		}
		current = current->next;
	}
	if (printOut == "") {
		cout << term << " does not exist in this dictionary" << endl;
		if (!memory.checkexistence(term)) {
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
void List::printSection(string section) {
	Node *current = this->head;
	string temp;
	int colIdx;
	int len;
	string printOut = "";
	while (current != NULL) {
		colIdx = current->value.find_last_of(":");
		len = current->value.length() - 1;
		temp = current->value.substr(colIdx, len);
		if (temp == section) {
			printOut = current->value.substr(0, colIdx);
			int counter = 0;
			string tempString = "";
			while (counter != printOut.length()) {
				if (printOut.at(counter) == '[') {
					cout << endl;
				}
				else if (printOut.at(counter) == '@') {
					tempString += "@";
					while ((printOut.at(counter + 1) != ' ') && (counter + 1 != printOut.length())) {
						counter++;
						tempString += printOut.at(counter);
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
					cout << printOut.at(counter);
				}
				counter++;
			}
		}
		current = current->next;
	}
}

string removeWhiteSpace(string term) {
	string newTerm = "";
	for (int i = 0; i < term.length(); i++) {
		if (term[i] != ' ') newTerm += term[i];
	}
	return newTerm;
}
void searchTermAll() {
	cout << "\nEnter term - ";
	string inTerm; 
	getline(cin, inTerm);
	term.printSearchDef(inTerm);
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
	int numChap = 0;
	int numSec = 0;
	char subSelection = 0;
	cout << "\n------------------------------";
	cout << "\n         SORT TERMS";
	cout << "\n------------------------------\n";
	cout << "1. Individual Section" << endl;
	cout << "2. Individual Chapter" << endl;
	cout << "3. Selection of Sections" << endl;
	cout << "4. Selection of Chapters" << endl;
	cout << "5. Sort Entire Dictionary" << endl;
	cout << "6. Go Back" << endl;
	cout << "\nchoice - " << endl;
	cin >> selection;
	if (cin.fail() || (selection != 1) && (selection != 2) && (selection != 3) && (selection != 4) && (selection != 5) && (selection != 6)) {
		cout << "Invalid input." << endl;
		cin.clear();
		cin.ignore(1024, '\n');
		*userNum = 3;
		cout << endl;
	}
	if (selection == 1) {
		cout << "Enter the section number: " << endl;
		cin >> numSec;
		*userNum = 4;
	}
	if (selection == 2) {
		cout << "Input the number of Chapter:" << endl;
		cin >> numChap;
		cout << "a. Sort Chpater by Section" << endl;
		cout << "b. Sort Entire Chapter" << endl;
		cin >> subSelection;
		if ((subSelection != 'a') || (subSelection != 'b')) {
			cout << "Invalid input." << endl;
			selection = 6;
		}
	}
	if (selection == 3) {
		cout << "a. Sort by Order of Sections" << endl;
		cout << "b. Sort Entire Selection" << endl;
		cin >> subSelection;
		if ((subSelection != 'a') || (subSelection != 'b')) {
			cout << "Invalid input." << endl;
			*userNum = 3;
		}
	}
	if (selection == 4) {
		cout << "a. Sort by Order of Chapters" << endl;
		cout << "b. Sort by Order of Sections" << endl;
		cout << "c. Sort Entire Selection" << endl;
		cin >> subSelection;
		if ((subSelection != 'a') || (subSelection != 'b') || (subSelection != 'c')) {
			cout << "Invalid input." << endl;
			*userNum = 3;
		}
	}
	if (selection == 5) {
		cout << "a. Sort by Chapters" << endl;
		cout << "b. Sort by Sections" << endl;
		cout << "c. Sort All" << endl;
		cin >> subSelection;
		if ((subSelection != 'a') || (subSelection != 'b') || (subSelection != 'c')) {
			cout << "Invalid input." << endl;
			*userNum = 4;
		}
	}
	if (selection == 6) {
		*userNum = 0;
	}
}
void search(int *userNum) {
	//declare linkedLists
	List *termsList = new List(); //change to *defList later
	List *defList = new List();
	List *allTerms = new List();
	
	//load
	allTerms->load("allTerms.txt");
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
		//cout << "Enter term - ";
		//searchTermAll();
		cout << "\nEnter term - ";
		string inTerm;
		getline(cin, inTerm);
		term.printSearchDef(inTerm);
		*userNum = 1;
	}
	if (select == 2) {
		cout << "Enter Chapter Number - ";
		int chIn; cin >> chIn;
		if (chIn == 1) {
			termsList->load("1Def.txt");
			cout << "Enter term - ";
			string searchInCh; cin >> searchInCh;
			termsList->printSearch(searchInCh);
			cout << endl;
		}
		else if (chIn == 2) {
			termsList->load("2Def.txt");
		}
		else if (chIn == 3) {
			termsList->load("3Def.txt");
		}
		else if (chIn == 4) {
			termsList->load("4Def.txt");
			cout << "Enter term - ";
			string searchInCh; cin >> searchInCh;
			cout << endl;
			termsList->printSearchDef(searchInCh);
			cout << endl;
		}
		else if (chIn == 5) {
			termsList->load("5Def.txt");
		}
		else if (chIn == 6) {
			termsList->load("6Def.txt");
		}
		else if (chIn == 7) {
			termsList->load("7Def.txt");
			cout << "Enter term - ";
			string searchInCh; cin >> searchInCh;
			cout << endl;
			termsList->printSearchDef(searchInCh);
			cout << endl;
		}
		else if (chIn == 9) {
			termsList->load("9Def.txt");
		}
		else if (chIn == 10) {
			termsList->load("10Def.txt");
		}
		else if (chIn == 11) {
			termsList->load("11Def.txt");
		}
		else {
			cout << "Chapter does not exist";
		}
		*userNum = 1;
	}
	if (select == 3) {
		*userNum = 0;
	}
}

void view(int *userNum) {
	int VDSelection = 0;
	int chIn = 0;
	int VDnumSec = 0;
	cout << "\n---------------------------------------------------";
	cout << "\n                VIEW DICTIONARY";
	cout << "\n---------------------------------------------------\n";
	cout << "1. Individual Section" << endl;
	cout << "2. Individual Chapter" << endl;
	cout << "3. Selection of Sections" << endl;
	cout << "4. Selection of Chapters" << endl;
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
		cout << "Input which sections you want to view: " << endl;
		//FIXME: create method that allows user to print out only requested sections  
		*userNum = 3;
	}
	if (VDSelection == 4) {
		cout << "Input which chapters you want to view: " << endl;
		//FIXME: create method that allows user to print out only requested chapters 
		*userNum = 3;
	}
	if (VDSelection == 5) {
		cout << "\n------------------------------------------------------------------------------";
		cout << "\nUF COT3100 SPRING 2018 - IMPORTANT TERMS";
		cout << "\n------------------------------------------------------------------------------\n";
		def01.print();
		def02.print();
		def03.print();
		//def04.print();
		def05.print();
		def06.print();
		def07.print();
		def09.print();
		def10.print();
		def11.print();

		//FIXME: create method that prints out entire dictionary
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
				numDef.printSection(inSec);
				cout << endl;
			}
			else cout << "\nThis section does not exist in Chapter 1\n";
		}
		if (chp == 2) {
			if ((section >= 1 && section <= 4) || section == 6) {
				//do something
			}
			else cout << "\nThis section does not exist in Chpater 2\n";
		}
		if (chp == 3) {
			if (section >= 1 && section <= 3) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 3\n";
		}
		if (chp == 4) {
			if (section >= 1 && section <= 3) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 4\n";
		}
		if (chp == 5) {
			if (section >= 1 && section <= 3) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 5\n";
		}
		if (chp == 6) {
			if (section >= 1 && section <= 3) {
				//do something
			}
			else cout << "\nThis section does exist in Chapter 6\n";
		}
		if (chp == 7) {
			if (section >= 1 && section <= 3) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 7\n";
		}
		if (chp == 9) {
			if (section == 1 || section == 3 || section == 5) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 9\n";
		}
		if (chp == 10) {
			if (section >= 1 && section <= 8) {
				//do something
			}
			else cout << "\nThis section does not exist in Chapter 10\n";
		}
		if (chp == 11) {
			if (section >= 1 && section <= 5) {
				//do something
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
		cout << "\nchapter 4 faulty asf, pls fix\n";
		//def04.print();
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

//probably won't need and probably will delete
void modifiable(int*userNum) {
	cout << "\n---------------------------------------------------";
	cout << "\n                USER INPUTTED TERMS";
	cout << "\n---------------------------------------------------\n";
	*userNum = 0;
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

	if (term.checkexistence(word)) {
		cout << word << " already exists." << endl;
	}
	else {
		definition.addTerm(def);
		term.addTerm(word);
	}
	cout << endl;
	*userNum = 0;
}
void deletion(int *userNum) {
	string weebs;
	cout << "Which word do you want to remove?" << endl;
	cin >> weebs;
	int index = term.deleteTerm(weebs);

	if (index == -1) {
		cout << "This term does not exist." << endl;
	}
	else {
		definition.deleteTermDetails(index);
		cout << weebs << " removed successfully." << endl;
	}
	cout << endl;
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
