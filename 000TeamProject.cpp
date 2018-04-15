#include"Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//stack method implementation

void stack::push(string value) {
	struct node *ptr = new node;
	ptr->data = value;
	if (top == NULL) {
		ptr->next = NULL;
	}
	else {
		ptr->next = top;
	}
	top = ptr;
}

void stack::pop() {
	struct node *temp;
	if (top == NULL) {
		cout << "Stack is empty." << endl;
	}
	temp = top;
	top = top->next;
	delete temp;
}

void stack::display() {
	struct node *temp = top;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

bool stack::empty()
{
	if (top == NULL)
	{
		return true;
	}
	else return false;
}

string stack::topOfStack()
{
	struct node *temp;
	if (top == NULL) {
		cout << "Stack is empty." << endl;
	}
	temp = top;
	top = top->next;
	return temp->data;
}

string stack::checkTop()
{
	struct node *temp;
	if (top == NULL) {
		cout << "Stack is empty." << endl;
	}
	temp = top;
	return temp->data;
}

bool stack::checkStack(string value) {
	struct node *ptr = new node;
	ptr = top;
	while (true)
	{
		if (ptr == NULL) return false;
		if (ptr->data == value) return true;
		ptr = ptr->next;
	}

}

List::List(){ this->head = NULL; }

void List::addTerm(string term) {
    if(head==NULL){
        head = new Node();
        head->value = term;
        size++;
        return;
    }
    
    Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=new Node();
    temp->next->value=term;
    size++;
}

int List::deleteTerm(string term) {
	Node * temp = head;
	int index = 0;
	while(temp != NULL) {
		if(temp->value == term) {
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
	for(int i = 0; i < index; i++) {
		temp = temp->next;
	}
	temp->value = "";
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
