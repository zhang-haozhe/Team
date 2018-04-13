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
	void addTerm(string term);
	int deleteTerm(string term);
	void deleteTermDetails(int index);
	void load(string fileName);
	Node*merge(Node*h1, Node*h2);
	void MergeSort(Node**head);
	bool checkexistence(string pagename);
	Node*getHead();
	int getSize();
	void print();
};
#pragma once