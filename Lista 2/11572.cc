#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>


using namespace std;

template <typename A, typename B>
int max (A a, B b ) {return (a>b ? a : b);}


int main(int argc, char **argv)
{
	int n,nsf;
	vector<int> snowflakes;
	int sf;
	string input;
	int longestSeq;
	vector<int> longest;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		cin >> nsf;
		for ( int i = 0 ; i < nsf ; i++ ) {
			cin >> sf;
			snowflakes.push_back(sf);
		}
		for ( int j = 0 ; i < nsf ; j++) {
			for ( int i = j ; i < nsf ; i++ ){
				auto index = find(longest.begin(),longest.end(), snowflakes[i]);
				cout << "index = " << index << endl;
				if (index != longest.end()){
					longestSeq = max(longest.size(),longestSeq);
					longest.clear();
				}
				else longest.push_back(snowflakes[i]);
			}
		}
		
		
	},

	
	
	return 0;
}

