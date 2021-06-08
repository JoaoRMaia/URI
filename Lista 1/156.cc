#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
	string input = "";
	string inputUpper;
	vector<pair<string,string>> dict;
	vector<string> ananagramas;
	while (1) {
		cin >> input;
		if (input == "#") break;
		ananagramas.push_back(input);
		inputUpper = input;
		for (auto& c : inputUpper) c = toupper(c);
		sort(inputUpper.begin(),inputUpper.end(), [](char a, char b) {return a<b;});
		dict.push_back(pair<string,string>{input,inputUpper});
	}
	for (auto& a : dict) {
		for (auto& b : dict){
			if (a.second == b.second && &a != &b ) {
				ananagramas.erase(remove(ananagramas.begin(), ananagramas.end(), a.first),ananagramas.end());
				break;
			}
		}
	}
	sort(ananagramas.begin(),ananagramas.end());
	for ( auto a : ananagramas ) cout << a << endl;
	return 0;
}

