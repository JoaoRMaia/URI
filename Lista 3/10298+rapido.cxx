#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	//ofstream out;
	//out.open("output.txt");
	string input;
	string candidato;
	bool flag;
	unsigned i,j;
	while(1){
		cin >> input;
		flag = false;
		if (input == ".") break;
		for ( i = 1 ; i < input.size() ; i++) {
			candidato = string{input,0,i};
			if (input.size() % i != 0) continue;
			for ( j = 0 ; j < input.size()-i ; j+=i){
				if (candidato != input.substr(j+i,i)) {
					flag = false;
					break;
				}
				flag = true;
			}
			if (!flag) continue;
			break;
		}
		cout << input.size()/i << endl;;
	}
	
	return 0;
}

