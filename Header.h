#include <iostream>
#include <string>
#include <fstream>
#include<io.h>
#include<fcntl.h>


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
public:
	List();
	void addTerm(string term);
	int deleteTerm(string term);
	void deleteTermDetails(int index);
	void load(string fileName);
	void print();
	Node*merge(Node*h1, Node*h2);
	void MergeSort(Node**head);
};
#pragma once
