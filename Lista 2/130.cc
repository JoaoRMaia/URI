#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> romanos;
	int n,k;
	int it;
	pair<int,int> morto;
	pair<int,int> enterrou;
	while (1) {
		cin >> n >> k;
		it = k-1;
		for (int i = 0 ; i < n ; i++) romanos.push_back(i+1);
		if (!romanos.size()) break;
		
		while (1){
			morto = pair<int,int>{it%romanos.size(),romanos[it%romanos.size()]},
			cout << "Removi o " << morto.second << " da posicao " << morto.first << endl;
			romanos.erase(romanos.begin() + morto.first);   // descobre quem morreu e tira ele do circulo
			it = (it+k-1)%romanos.size();
			enterrou = pair<int,int>{it,romanos[it]},
			if (romanos.size() == 1) break;
			cout << "Removi o " << enterrou.second << " da posicao " << enterrou.first << endl;
			romanos.erase(romanos.begin() + enterrou.first);
			cout <<" Vou adicionar o " << enterrou.second << " Na posicao " << morto.first << endl;
			cout << "Enterrou first = " << enterrou.first << "e size = " << romanos.size() << endl;
			if (morto.first >= (int) romanos.size()) romanos.push_back(enterrou.second);
			else romanos.emplace(romanos.begin()+morto.first,enterrou.second);
			cout << "enterrou.first = " << enterrou.first << "tam do vetor " << romanos.size() << endl;
			cout << "it = " << it << endl;
			cout << " O vetor esta ";
			for ( auto a : romanos ) cout << a;
			cout << endl;
			
		}
		cout <<" Sai do loop" << endl;
		cout << romanos[0] << endl;
		
	}
	return 0;
}

