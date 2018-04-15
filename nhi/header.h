#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void creditList(int* userNum);
void userMenu(int* userNum);
void addition(int* userNum);
void deletion(int* userNum);
void sort(int* userNum);
void previous(int* userNum);
void search(int* userNum);


class Node {
public:
	Node * next;
	string value;
};

class List {
private:
	int size;
	Node* head;
	Node*tail;
public:
	List();
	void addTerm(string data);
	int deleteTerm(string data);
	void deleteTermDetails(int index);
	void load(string fileName);
	void insertAtBeginning(Node**start);
	void bubbleSort(Node*start);
	void swap(Node*a, Node*b);
	Node*getHead();
	Node*getTail();
	string getValue();
	Node*getNext();
	int getSize();
	void print();

	//mergesort, extra shit
	Node*merge(Node*h1, Node*h2);
	void MergeSort(Node**head);
};

void printTermAndDef();