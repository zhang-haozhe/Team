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
	Node*getHead();
	Node*getTail();
	//string getValue();
	Node*getNext();
	int getSize();

	//bubble sort
	void insertAtBeginning(Node**start);
	void bubbleSort(Node*start);
	void swap(Node*a, Node*b);
	void insertAtBeginningDef(Node**start);
	void bubbleSortDef(Node*start);
	void swapDef(Node*a, Node*b);
	
	//mergesort, extra shit
	Node*merge(Node*h1, Node*h2);
	void MergeSort(Node**head);

	//search
	bool search(Node*head, string term);
	void printSearch(string term);
	void printSearchDef(string term);

	//printing
	void printDef();
	void printTerms(); 
};

void printTermAndDef(List*terms, List*definitions);
