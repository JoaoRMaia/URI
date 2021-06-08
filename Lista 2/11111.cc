#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
	stack<pair<int,int>> mat;
	int n;
	string input;
	stringstream ss;
	bool m;
	while (true){
		while (!mat.empty()) mat.pop();
		m = true;
		getline(cin,input);
		if (input[0] == '\0') break;
		ss << input;
		while (ss >> n && m) {
			if ( n < 0 ) {
				if (mat.empty()) {
					mat.push(pair<int,int>{(-n),(-n)});					
				}
				else {
					if (mat.top().second <= -n) {
						m = false;
					}
					mat.top().second += n;
					mat.push(pair<int,int>{(-n),(-n)});
				}
			}
			else {
				if (!mat.empty() && mat.top().first == n ) {
					mat.pop();
				}
				else {
					m = false;
				}
					
			}
		}
		
		
		if (m && mat.empty()) cout << ":-) Matrioshka!" << endl;
		else cout << ":-( Try again." << endl;
		ss.str("");
		ss.clear();
		
	}
	return 0;
}

