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
void table(int* userNum);
void sortAndPrint(int* userNum);


class Node {
public:
	Node * next;
	string value;
};

class List {
private:
	int size;
	Node* head;
public:
	List();
	Node*getHead();
	int getSize();
	void addTerm(string term);
	int deleteTerm(string term);
	void deleteTermDetails(int index);
	void load(string fileName);
	bool checkexistence(string pagename);
	void print();

	//bubblesort methods
	void insertAtBeginning(Node**start);
	void bubbleSort(Node*start);
	void swap(Node*a, Node*b);
	
	//search
	bool search(Node*head, string term);
	void printSearch(string term);
	void printSearchDef(string term);
};

//stack implementation
struct node
{
	string data;
	struct node *next;
};

class stack
{
	struct node *top;
public:
	stack() {
		struct node *top = NULL;
	}
	void push(string value);
	void pop();
	void display();
	bool empty();
	string topOfStack();
	string checkTop();
	bool checkStack(string value);
};

#pragma once
