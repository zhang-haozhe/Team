#include"Header.h"

using namespace std;

List::List() { this->head = NULL; }

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
void List::print() {
	Node *temp = new Node;
	temp = head;
	int counter = 0;
	string tempString;
	while (temp != NULL) {
		if (temp->value != "Free") {
			while (counter < temp->value.length()) {
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
						cout << "u2211";
					}
					else if (tempString == "@u222a") { //union
						cout << "u222a";
					}
					else if (tempString == "@u2229") { //intersection
						cout << "u2229";
					}
					else if (tempString == "@u2295") {//exclusive or
						cout << "u2295";
					}
					else if (tempString == "@u2192") { //right arrow
						cout << "u2192";
					}
					else if (tempString == "@u2286") { // subset of
						cout << "u2286";
					}
					else if (tempString == "@u2261") { // equivalent (three lines)
						cout << "u2261";
					}
					else if (tempString == "@u2200") { // for all
						cout << "u2200";
					}
					else if (tempString == "@u2203") { // there exists
						cout << "u2203";
					}
					else if (tempString == "@u2081") { // subscript 1
						cout << "u2081";
					}
					else if (tempString == "@u2082") { // subscript 2
						cout << "u2082";
					}
					else if (tempString == "@u2099") { // subscript n
						cout << "u2099";
					}
					else if (tempString == "@u2308") { // left ceiling
						cout << "u2308";
					}
					else if (tempString == "@u2309") { // right ceiling
						cout << "u2309";
					}
					else if (tempString == "@u2260") { //not equal sign
						cout << "u2260";
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

	*userNum = 0;
}

void previous(int *userNum) {

	*userNum = 0;
}




int main() {
	int userInput;
	int* userNum = &userInput;
	List definition;
	List term;
	definition.load("1Definitions.txt");
	term.load("1Terms.txt");
	definition.print();

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
			break;
		}case 5: {
			search(userNum);
			break;
		}case 6: {
			creditList(userNum);
			break;
		}
		}userMenu(userNum);
	} while (*userNum != 8);

	return 0;
}