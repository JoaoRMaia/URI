#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

typedef struct carta {
	string num;
	string naipe;
	carta() {}
	carta( string c ) { 
		num = c[0];
		naipe = c[1];
	}
	int value(){
		if ( num[0] == 'A' || num[0] == 'K' || num[0] == 'Q' || num[0] == 'J' || num[0] == 'T') return 10;
		else return stoi(num);
	}
	
}Carta;
	
int main () {
	vector<carta> deck;
	string c;
	int n;
	int y;
	int val;
	int topo;
	cin >> n;
	for ( int i = 0; i < n ; i++){
		for ( int i = 0; i < 52 ; i++) {
		cin >> c;
		deck.push_back(Carta(c));
		}
		topo = 26;
		y = 0;
		for (int i = 0 ; i < 3 ; i++){
			val = deck[topo].value();
			y+= val;
			deck.erase(deck.begin()+topo);
			topo--;
			
			for ( int i = 0 ; i < 10-val ; i++) {
				deck.erase(deck.begin()+topo-i);
			}
			topo-=(10-val);
		}
		cout << "Case "<< i+1 <<": " << deck[y-1].num << deck[y-1].naipe << endl;
		deck.clear();
		
	}
	return 0;
}
