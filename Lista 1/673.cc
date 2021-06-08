#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

int main () {
	string nu;
	getline(cin,nu);
	int n = stoi(nu);
	stack<char> s;
	string input;
	int valido;
	for (int i = 0 ; i < n ; i++) {
		getline(cin,input);
		valido = 1;
		for (char ch : input){
			if ( ch == '(' || ch == '[' ) s.push(ch);
			else if ( ch == ')' && !s.empty() && s.top() == '(' ) s.pop();
			else if ( ch == ']' && !s.empty() && s.top() == '[' ) s.pop();
			else valido = 0;
		}
		if (valido && s.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
		
		while (!s.empty()) s.pop();
		
	}
	return 0;
}
