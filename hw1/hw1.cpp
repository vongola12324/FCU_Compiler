#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int intAmount = 0, floatAmount = 0, idAmount = 0, errAmount = 0;

bool isInteger(string str) {
	bool isInt = true;
	for(int i=0;i<str.length();i++){
		if (i==0) {
			if (!(isdigit(str[i]) || str[i] == '+' || str[i] == '-')) {
				isInt = false;
			}	
		} else if (i==str.length()-1) {
			if (str[i] != ';') {
				isInt = false;
			}		
		} else {
			if (!isdigit(str[i])) {
				isInt = false;
			}
		}
	}
	return isInt;
}

bool isFloat(string str) {
	bool isF = true, hasDot = false;
	for(int i=0;i<str.length();i++){
		if(i==0) {
			if (!isdigit(str[i]) && str[i] != '+' && str[i] != '-') {
				isF = false;
			}	
		} else if (i==str.length()-1) {
			if (str[i] != ';') {
				isF = false;
			}		
		} else {
			if (hasDot && str[i] == '.') {
				isF = false;
			} else if (str[i] == '.') {
				hasDot = true;
			} else if (!isdigit(str[i])) {
				isF = false;
			}
		}
	}
	return isF;
}

bool isID(string str){
	bool isId = true;
	for(int i=0;i<str.length();i++){
		if(i==0){
			if(!isalpha(str[i])) {
				isId = false;
			}
		} else if (i==str.length()-1) {
			if (str[i] != ';') {
				isId = false;
			}		
		} else {
			if(!isalnum(str[i]) && str[i]!='_') {
				isId = false;
			}
		}
	}
	return isId;
}

void checkStr(string str) {
	if(isInteger(str)){
		cout << "Find a Integer: " << str << endl;
		intAmount++;
	} else if (isFloat(str)) {
		cout << "Find a Float: " << str << endl;
		floatAmount++;

	} else if (isID(str)) {
		cout << "Find a ID: " << str << endl;
		idAmount++;

	} else {
		cout << "Find a Error: " << str << endl;
		errAmount++;
	}
}

int main(void) {
	string str;
	while(getline(cin, str)){
		checkStr(str);		
	}
	cout << "Float Amount: " << floatAmount << endl;
    cout << "Integer Amount: " << intAmount << endl;
	cout << "ID Amount: " << idAmount << endl;
	cout << "Err Amount: " << errAmount << endl;
	return 0;
}
