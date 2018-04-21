#ifndef PA3
#define PA3

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

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

#endif#pragma once
