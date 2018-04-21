#include <string>

using namespace std;

string strToUpper(string str) {

	for (int i = 0; i < str.size(); i++) {
		str.at(i) = toupper(str.at(i));
	}

	return str;
}

int main() {
	
	string str = "String";
	str = strToUpper(str);
	cout << str << endl;

	system("pause");
	return 0;
}
