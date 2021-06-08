#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string input;
	string candidato;
	int n;
	while(1){
		cin >> input;
		if (input == ".") break;
		for ( unsigned i = 1 ; i <= input.size() ; i++) {
			candidato = string{input,0,i};
			if (input.size() % i != 0) continue;
			for ( unsigned j = 0 ; j < input.size()/i ; j++){
				if ( j == (input.size()/i)-1) {
					n = j+1;
					input.clear();
					break;
					
				}
				else if (!((j+1)*i < input.size() && candidato == input.substr((j+1)*i,i))) break;
			}
		}
		if (!input.empty()) cout << "1" << endl;
		else cout << n << endl;;
	}
	
	return 0;
}

