#include <iostream>
#include <stack>
#include <fstream>

using namespace std;

stack<int> st;
int j,n,carro;

void car(){
	
	while (n) {
		j = 0;
		for ( int i = 0; i < n ; i++) {
			cin >> carro;
			if (!carro) return;			
			while ( j < n && j != carro ) {
				if(!st.empty() && st.top() == carro) break;
				j++;
				st.push(j);
			}
			if(st.top() == carro) st.pop();
		}
		if (st.empty()) cout <<"Yes\n" << endl;
		else cout << "No\n" << endl;
		while(!st.empty()) st.pop();
	}
}


int main(int argc, char **argv) {
	while (1) {
		cin >> n;
		if (!n) break;
		car();
		cout << endl;
	}
	return 0;
}

