#include <iostream>
#include <string>
#include <fstream>


using namespace std;



void userMenu(int* userNum);
void search(int* userNum);
void searchByCh(int chIn);
void previous(int* userNum);
void view(int* userNum);
void viewBySection();
void viewByCh();
void viewSelCh();
void sort(int* userNum);
void toc(int* userNum);
void help(int* userNum);
void creditList(int* userNum);

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
	bool contains(string term);
	void print();

	//bubblesort methods
	void insertAtBeginning(Node**start);
	void bubbleSort(Node*start);
	void swap(Node*a, Node*b);

	//search
	bool search(Node*head, string term);
	void printSearch(string term);
	void printSearchDef(string term);
	string strToUpper(string str);
	string removeWhiteSpace(string term);

	void printMemory();
	void printSection(string sec);
};



#pragma once
