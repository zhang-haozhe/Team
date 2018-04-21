#include "pa3.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

int main()
{
	fstream file;
	string word, filename;
	cout << "Please enter the name of the input file: " << endl;
	// filename of the file
	cin >> filename;

	//temp stacks, have to analyze later 
	stack keywords, identifiers, constants, operators, delimiters, syntax, loopAnalysis;
	
	//loop data...
	int completeLoop = 0;
	bool checkParenthesis = true;
	
	// opening file
	file.open(filename.c_str());
	
	//if file cannot open
	if (!file) {
		cout << "Could not open file " << filename << endl;
		exit(1);
	}

	// extracting words form the file
	while (file >> word)
	{
		int startIndex = 0;
		int endIndex = 0;

		for (int i = 0; i < word.length(); i++)
		{
			//find keywords or identifiers...also looking for complete loops:
			if (isalpha(word[i]) || word[i] == '(' || word[i] == ')')
			{
				startIndex = i++;
				//while it's letter of alphabet
				while (isalpha(word[i]))
				{
					//get length of word
					++i;
				}
				endIndex = i - startIndex;

				//get word
				string wordToPush = word.substr(startIndex, endIndex);
				if (isupper(wordToPush[0])) {
					keywords.push(wordToPush);

				}
				else {
					identifiers.push(wordToPush);
				}
				if (wordToPush == "FOR")
				{
					loopAnalysis.push(wordToPush);
				}
				if (word[i] == '(')
				{
					loopAnalysis.push("(");
				}
				if (word[i] == ')')
				{
					if (loopAnalysis.checkTop() == "(")
					{
						loopAnalysis.pop();   //pop '('
						checkParenthesis = true;
					}
					else {
						checkParenthesis = false;
					}
				}
				if (checkParenthesis == true)
				{
					if (wordToPush == "BEGIN")
					{
						if (loopAnalysis.checkTop() == "FOR")
						{
							loopAnalysis.push(wordToPush);
						}
					}
					if (wordToPush == "END")
					{
						if (loopAnalysis.checkTop() == "BEGIN")
						{
							loopAnalysis.pop();   //pop BEGIN 
							if (loopAnalysis.checkTop() == "FOR")
							{
								loopAnalysis.pop();   //pop FOR
								++completeLoop;
							}
						}
					}
				}

			}
			//find constants
			if (isdigit(word[i]))
			{
				startIndex = i++;
				while (isdigit(word[i]))
				{
					++i;
				}
				endIndex = i - startIndex;
				string constantToPush = word.substr(startIndex, endIndex);
				constants.push(constantToPush);
			}
			//find operators
			if (word == "++)")
			{
				operators.push("++");
			}
			else if (word.length() == 1 && word == "+")
			{
				operators.push(word);
			}
			else if (word == "-")
			{
				operators.push(word);
			}
			else if (word == "*")
			{
				operators.push(word);
			}
			else if (word == "/")
			{
				operators.push(word);
			}
			else if (word.find("=") != 'j')
			{
				bool hasEqual = true;
				if (hasEqual == true)
				{
					operators.push("=");
				}
			}
			//find delimiters
			if (word[i] == ',' || word[i] == ';')
			{
				delimiters.push(word.substr(i, 1));
			}
			//find parenthesis
			if (word[i] == '(' || word[i] == ')')
			{
				syntax.push(word.substr(i,1));
			}
		}
	}
	//analyze each stack for validity...put all clean tokens here:
	stack checkKeywords, checkIdentifiers, checkConstants, checkOperators, checkDelimiters, syntaxError;
	string possibleKeyword;
	string valididentifier;
	string validConstant;
	string validOperator;
	string validDelimiter;
	int forCounter = 0;
	int beginCounter = 0;
	int endCounter = 0;

	while (!keywords.empty())
	{
		possibleKeyword = keywords.topOfStack();
		if (possibleKeyword == "FOR" || possibleKeyword == "BEGIN" || possibleKeyword == "END")
		{
			if (!checkKeywords.checkStack(possibleKeyword))
			{
				checkKeywords.push(possibleKeyword);
			}
			if (possibleKeyword == "FOR")
			{
				++forCounter;
			}
			if (possibleKeyword == "BEGIN")
			{
				++beginCounter;
			}
			if (possibleKeyword == "END")
			{
				++endCounter;
			}
		}
		//if not "FOR", "BEGIN", OR "END", then push keyword to syntax error
		else {
			if (!syntaxError.checkStack(possibleKeyword))
			{
				syntaxError.push(possibleKeyword);
			}
		}
	}
	//once you get final FOR, BEGIN, AND END COUNT, compare values to see what you're missing:
	//correct syntax means FOR = BEGIN = END:
	//missing a BEGIN case:
	if (beginCounter < forCounter)
	{
		if (!syntaxError.checkStack("BEGIN")) {
			syntaxError.push("BEGIN");
		}
	}
	//missing an END case:
	if (endCounter < forCounter)
	{
		if (!syntaxError.checkStack("END")) {
			syntaxError.push("END");
		}
	}
	//missing a BEGIN and END case:
	if (beginCounter < forCounter && endCounter < forCounter)
	{
		if (!syntaxError.checkStack("BEGIN")) {
			syntaxError.push("BEGIN");
		}
		if (!syntaxError.checkStack("END")) {
			syntaxError.push("END");
		}
	}

	while (!identifiers.empty())
	{
		valididentifier = identifiers.topOfStack();
		if (!checkIdentifiers.checkStack(valididentifier))
		{
			checkIdentifiers.push(valididentifier);
		}
	}

	while (!constants.empty())
	{
		validConstant = constants.topOfStack();
		if (!checkConstants.checkStack(validConstant))
		{
			checkConstants.push(validConstant);
		}
	}

	while (!operators.empty())
	{
		validOperator = operators.topOfStack();
		if (!checkOperators.checkStack(validOperator))
		{
			checkOperators.push(validOperator);
		}
	}

	while (!delimiters.empty())
	{
		validDelimiter = delimiters.topOfStack();
		if (!checkDelimiters.checkStack(validDelimiter))
		{
			checkDelimiters.push(validDelimiter);
		}
	}
	//are parenthesis balanced? if not, push to syntax error 
	string parethesistracker;
	int leftParenthesis = 0;
	int rightParenthesis = 0;
	while (!syntax.empty())
	{
		parethesistracker = syntax.topOfStack();
		if (parethesistracker == ")")
		{
			++rightParenthesis;
		}
		else {
			++leftParenthesis;
		}
	}
	//if more right > left, then too many ")", so then push ")" to syntax error
	if (rightParenthesis > leftParenthesis)
	{
		syntaxError.push(")");
	}
	//if more left > right, then too many "(", so then push "(" to syntax error
	else if (leftParenthesis > rightParenthesis) {
		syntaxError.push("(");
	}

	//print nested loop count:
	cout << "The depth of nested loop(s) is ";
	if (completeLoop - 1 < 0) {
		cout << completeLoop;
	}
	else {
		cout << completeLoop - 1;
	}
	cout << endl<<endl;

	//print final stacks:
	cout << "Keywords: ";
	checkKeywords.display();
	cout << endl;
	cout << "Identifiers: ";
	checkIdentifiers.display();
	cout << endl;
	cout << "Constants: ";
	checkConstants.display();
	cout << endl;
	cout << "Operators: ";
	checkOperators.display();
	cout << endl;
	cout << "Delimiters: ";
	checkDelimiters.display();
	cout << endl;

	//print syntax errors:
	cout << "Syntax Error(s): ";
	if (!syntaxError.empty())
	{
		syntaxError.display();
		cout << endl;
	}
	else if (syntaxError.empty())
	{
		cout << "N/A" << endl<<endl;
	}
	system("pause");
	return 0;
}
