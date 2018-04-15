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
void List::print() {
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

int main() {
	//Node**head = NULL;
	
	string termsFile = "termsSample.txt";
	string defFile = "definitionsSample.txt";

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
	termsList->print();

	system("pause");
	return 0;



}
