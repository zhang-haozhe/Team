#include"Header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

List::List() { this->head = NULL; }
static List definition;
static List term;
static List number;



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
bool List::checkexistence(string pagename) {//check if there is a node with such a name
	Node * temp = new Node;
	temp = head;
	while (temp != NULL) {
		if (temp->value == pagename) {
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
bool List::search(Node*head, string term) {
	Node*current = head;
	//int compareStr;
	while (current != NULL) {
		string currUpper = strToUpper(current->value);
		string termUpper = strToUpper(term);
		if (currUpper == termUpper) {
			return true;
		}
		current = current->next;
	}
	return false;
}
void List::printSearch(string term) {
	if (search(this->head, term)) {
		cout << term << endl;
	}
	else {
		cout << term << " does not exist in this dictionary" << endl;
	}
}
void List::printSearchDef(string term) {
	Node*current = this->head;
	string temp;
	int parenIdx;
	string printOut = "";
	while (current != NULL) {
		parenIdx = current->value.find_first_of(":");
		temp = current->value.substr(0, parenIdx);
		if (strToUpper(temp) == strToUpper(term)) {
			//cout << current->value << endl;
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
		current = current->next;
	}
	if (printOut == "") {
		cout << term << " does not exist in this dictionary" << endl;
	}
}
string List::strToUpper(string str) {
	for (int i = 0; i < str.size(); i++) {
		str.at(i) = toupper(str.at(i));
	}
	return str;
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
void userMenu(int* userNum) {
	while (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8) || (*userNum == 9))) {
		cout << "\n-------------------------";
		cout << "\n        MAIN MENU";
		cout << "\n-------------------------\n";
		cout << "1. Search Term" << endl;
		cout << "2. Previous Searches" << endl;
		cout << "3. Sort Dictionary" << endl;
		cout << "4. View Dictionary" << endl;
		cout << "5. Modifiable Dictionary" << endl;
		cout << "6. Table of Contents" << endl;
		cout << "7. About and Help" << endl;
		cout << "8. Credits" << endl;
		cout << "9. Quit" << endl;
		cout << endl;
		cout << "choice - ";
		cin >> *userNum;
		if (!((*userNum == 1) || (*userNum == 2) || (*userNum == 3) || (*userNum == 4) || (*userNum == 5) || (*userNum == 6) || (*userNum == 7) || (*userNum == 8) || (*userNum == 9))) {
			cout << endl;
			cout << "Invalid Input." << endl;
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
void sort(int *userNum) {
	int selection = 0;
	int numChap = 0;
	int numSec = 0;
	char subSelection = 0;
	do {
		cout << "\n------------------------------";
		cout << "\n         SORT TERMS";
		cout << "\n------------------------------\n";
		cout << "1. Individual Section" << endl;
		cout << "2. Individual Chapter" << endl;
		cout << "3. Selection of Sections" << endl;
		cout << "4. Selection of Chapters" << endl;
		cout << "5. Sort Entire Dictionary" << endl;
		cout << "6. Go Back" << endl;
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
			*userNum = 3;
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
				*userNum = 3;
			}
		}
		if (selection == 6) {
			*userNum = 0;
		}
	} while ((cin.fail()) || ((selection != 1) && (selection != 2) && (selection != 3) && (selection != 4) && (selection != 5)));
	*userNum = 3;
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
		cout << "Enter term - ";
		string searchTerm; cin >> searchTerm;
		allTerms->printSearch(searchTerm);
		cout << endl;
		*userNum = 1;
	}
	if (select == 2) {
		cout << "Enter Chapter Number - ";
		int chIn; cin >> chIn;
		if (chIn == 1) {
			termsList->load("1terms.txt");
			cout << "Enter term - ";
			string searchInCh; cin >> searchInCh;
			termsList->printSearch(searchInCh);
			cout << endl;
		}
		else if (chIn == 2) {
			termsList->load("2terms.txt");
		}
		else if (chIn == 3) {
			termsList->load("3terms.txt");
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
			termsList->load("5terms.txt");
		}
		else if (chIn == 6) {
			termsList->load("6terms.txt");
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
			termsList->load("9terms.txt");
		}
		else if (chIn == 10) {
			termsList->load("10terms.txt");
		}
		else if (chIn == 11) {
			termsList->load("11terms.txt");
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
void previous(int *userNum) {
	cout << "\n---------------------------------------------------";
	cout << "\n                PREVIOUS SEARCHES";
	cout << "\n---------------------------------------------------\n";
	*userNum = 0;
}
void table(int *userNum) {
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

void view(int *userNum) {
	int VDSelection = 0;
	int VDnumChap = 0;
	int VDnumSec = 0;

	do {
		cout << "\n---------------------------------------------------";
		cout << "\n                VIEW DICTIONARY";
		cout << "\n---------------------------------------------------\n";
		cout << "1. Individual Section" << endl;
		cout << "2. Individual Chapter" << endl;
		cout << "3. Selection of Sections" << endl;
		cout << "4. Selection of Chapters" << endl;
		cout << "5. View Entire Dictionary" << endl;
		cout << "6. Go Back" << endl;
		cin >> VDSelection;
		if (cin.fail() || (VDSelection != 1) && (VDSelection != 2) && (VDSelection != 3) && (VDSelection != 4) && (VDSelection != 5) && (VDSelection != 6)) {
			cout << "Invalid input." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			*userNum = 4;
			cout << endl;
		}
		if (VDSelection == 1) {
			cout << "Enter the section number: " << endl;
			cin >> VDnumSec;
			*userNum = 4;
		}
		if (VDSelection == 2) {
			cout << "Input the chapter number:" << endl;
			cin >> VDnumChap;
			*userNum = 4;
		}
		if (VDSelection == 3) {
			cout << "Input which sections you want to view: " << endl;
			//FIXME: create method that allows user to print out only requested sections  
			*userNum = 0;
		}
		if (VDSelection == 4) {
			cout << "Input which chapters you want to view: " << endl;
			//FIXME: create method that allows user to print out only requested chapters 
			*userNum = 0;
		}
		if (VDSelection == 5) {
			//FIXME: create method that prints out entire dictionary 
			*userNum = 0;
		}
		if (VDSelection == 6) {
			*userNum = 0;
		}
	} while ((cin.fail()) || ((VDSelection != 1) && (VDSelection != 2) && (VDSelection != 3) && (VDSelection != 4) && (VDSelection != 5)));
	*userNum = 4;
}

void modifiable(int*userNum) {
	cout << "\n---------------------------------------------------";
	cout << "\n                USER INPUTTED TERMS";
	cout << "\n---------------------------------------------------\n";
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


int main() {
	int userInput;
	int* userNum = &userInput;
	definition.load("1Definitions.txt");
	term.load("1Terms.txt");
	definition.print();

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
			sort(userNum);
			break;
		}case 4: {
			view(userNum);
			break;
		}case 5: {
			modifiable(userNum);
			break;
		}case 6: {
			table(userNum);
			break;
		}
		case 7: {
			help(userNum);
			break;
		}
		case 8: {
			creditList(userNum);
			cout << endl;
			break;
		}
		}userMenu(userNum);
	} while (*userNum != 9);

	return 0;
}
