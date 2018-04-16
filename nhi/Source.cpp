#include <iostream>
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

List::List() { 
	this->head = NULL; 
	this->tail = NULL;
}
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
Node*List::getTail() {
	return this->tail;
}
int List::getSize() {
	return this->size; 
}
Node*List::getNext() {
	Node * temp = new Node();
	temp = temp->next;
	return temp;
}
//mergesort, some extra bs, delete later maybe
Node*List::merge(Node* h1, Node*h2) {
	Node*t1 = new Node;
	Node*t2 = new Node;
	Node*temp = new Node;

	if (h1 == NULL) return h2; //return if first list is empty
	if (h2 == NULL) return h1; //return if second list is empty

	t1 = h1;

	while (h2 != NULL) {
		t2 = h2; //taking head node of second list as t2
		h2 = h2->next; //shifting 2nd list head to the next
		t2->next = NULL;
		//If the data value is less than the head of the first list, add that node at the beginning
		if (h1->value > t2->value) {
			t2->next = h1;
			h1 = t2;
			t1 = h1;
			continue;
		}
		//Traverse the first list
	flag:
		if (t1->next == NULL) {
			t1->next = t2;
			t1 = t1->next;
		}
		//traverse first list until t2->value is more than node's value
		else if ((t1->value) <= t2->value) {
			t1 = t1->next;
			goto flag;
		}
		//insert the node as t2->data is less than the next node
		else {
			temp = t1->next;
			t1->next = t2;
			t2->next = temp;
		}
	}
	//return head of new sorted list
	return h1;
}
void List::MergeSort(Node**head) {
	Node*first = new Node;
	Node*second = new Node;
	Node*temp = new Node;
	first = *head;
	temp = *head;
	//return if list has less than 2 nodes
	if (first == NULL || first->next == NULL) {
		return;
	}
	else {
		//Break the list into 2 halves with first and second as head of list
		while (first->next != NULL) {
			first = first->next;
			if (first->next != NULL) {
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}
	//divide and conquer
	MergeSort(&first);
	MergeSort(&second);
	//merge the 2 parts of the list into a sorted one
	*head = merge(first, second);
}
//bubblesort
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
void List::insertAtBeginningDef(Node**start) {
	Node*temp = new Node;
	temp->value;
	temp->next = *start;
	*start = temp;
}
void List::bubbleSortDef(Node*start) {
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
			string value1 = ptr->value;
			string value2 = ptr->next->value;
			int colIdx1 = value1.find_first_of(":");
			int colIdx2 = value2.find_first_of(":");
			string tempVal1 = value1.substr(0, colIdx1);
			string tempVal2 = value2.substr(0, colIdx2);
			if (tempVal1 > tempVal2) {
				swapDef(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		temp = ptr;
	} while (swapped);
}
void List::swapDef(Node*a, Node*b) {
	string temp = a->value;
	a->value = b->value;
	b->value = temp;
}

//seraching
bool List::search(Node*head, string term) {
	Node*current = head;
	while (current != NULL) {
		if (current->value == term) {
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

//print
void List::printDef() {
	Node *temp = new Node;
	temp = head;
	int counter = 0;
	string tempString;
	while (temp != NULL) {
		while (counter < temp->value.length()) {
			if (temp->value.at(counter) == '[') {
				cout << endl;
			}
			else if (temp->value.at(counter) == '\\') {
				tempString += "\\";
				while ((temp->value.at(counter) != ' ') && (counter != temp->value.length())) {
					counter++;
					tempString += temp->value.at(counter);
				}
				if (tempString == "\u00AC") {
					cout << "\u00AC" << endl;
				}
				tempString = "";
			}
			else {
				cout << temp->value.at(counter);
			}
			counter++;
		}
		temp = temp->next;
		counter = 0;
		cout << endl;
	}
}
void List::printTerms() {
	Node *temp = new Node;
	temp = head;
	int counter = 0;
	string tempString;
	while (temp != NULL) {
		//cout << temp->value << flush;
		if (temp->value != "Free") {
			while (counter < temp->value.length()) {
				if (temp->value.at(counter) == '[') {
					cout << endl;
				}
				else if (temp->value.at(counter) == '\\') {
					tempString += "\\";
					while ((temp->value.at(counter) != ' ') && (counter != temp->value.length())) {
						counter++;
						tempString += temp->value.at(counter);
					}
					if (tempString == "\u00AC") {
						cout << "\u00AC" << endl;
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
	}
}

int main() {
	//Node**head = NULL;
	
	string termsFile = "terms.txt";
	string defFile = "definitions.txt";

	//declare linked lists
	List *termsList = new List();
	List *defList = new List();

	int const numTerms = termsList->getSize();
	int const numDef = termsList->getSize();

	//practice with termsList first
	termsList->load(termsFile);
	//send reference of head into bubbleSort()
	Node*head = new Node;
	Node*tail = new Node;
	head = termsList->getHead();
	tail = termsList->getTail();
	termsList->bubbleSort(head);
	termsList->printTerms();
	cout << endl;

	//definitions
	defList->load(defFile);
	Node*defHead = defList->getHead();
	Node*defTail = defList->getTail();
	defList->bubbleSortDef(defHead);
	defList->printDef();
	cout << endl;

	//search testing
	termsList->printSearch("Descendants");
	termsList->printSearch("Left Child");
	termsList->printSearch("Bowcher");
	
	system("pause");
	return 0;
}
