#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// function to calculate whitespaces
int countWhiteSpace(string& str)
{
	int numWhiteSpace = 0;
	
	for (int i = 0; i < str.length(); i++) {
		int traverseString = str[i];
		if (isspace(traverseString))
			numWhiteSpace++;
	}
	return numWhiteSpace;
}

// Driver Code
int main()
{
	string str = "arbitrary string";
	cout << countWhiteSpace(str) << endl;
	system("pause");
	return 0;
}