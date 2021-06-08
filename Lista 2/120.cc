#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename t>
struct myStack : vector<t>  {
	void flip(int n) {
		int aux;
		for ( unsigned i = n-1 ; i <= this->size()/2 ; i++) {
			aux = (*this)[i];
			(*this)[i] = (*this)[this->size()-i+n-2];
			(*this)[this->size()-i+n-2] = aux;
		}
	}
},

int iMax(vector<int> v,int offset){
	int indice = 0;
	for (unsigned i = 0 ; i < v.size()-offset ; i++) if (v[i] > v[indice])  indice = i;
	cout << "Retornando " << v[indice] << endl;
	return indice;
}

int main(int argc, char **argv)
{
	myStack<int> stk;
	int a;
	string input;
	stringstream ss;
	int imax;
	
	while (getline(cin,input)){
		if (input[0] == '\0') break;
		ss << input;
		while ( ss >> a) stk.push_back(a);
		
		for (unsigned i = 0 ; i < stk.size() ; i++ ) {
		
			imax = iMax(stk,i);
			cout << "Maior = " << stk[imax] << endl;
			if ( (unsigned) stk[imax] == stk.size() - i - 1) {
				i++;
				cout << "i = " << i << endl;
				continue;
			}
			cout << endl;
			cout << "Flipa no " << imax << " ";
			stk.flip(imax+1);
			cout << "estado da pilha " << endl;
			for (auto it = stk.begin() ; it != stk.end() ; it++ ) cout << *it << " ";
			cout << " depois no " << stk.size()-i << " ";
			stk.flip (stk.size()-i);
			cout << "estado da pilha " << endl;
			for (auto it = stk.begin() ; it != stk.end() ; it++ ) cout << *it << " ";
			cout << endl;
		}
		cout << "Ficou" << endl;
		for (auto it = stk.begin() ; it != stk.end() ; it++ ) cout << *it << " ";
		ss.clear();
		stk.clear();
	
	
		
	}
	return 0;
}

