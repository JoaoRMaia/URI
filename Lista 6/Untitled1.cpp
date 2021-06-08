#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

std::fstream out;

void permuta(std::string vetor, int inf, int sup) {
	if(inf == sup) {
		for(int i = 0; i <= sup; i++)
			out << vetor[i];
		out << std::endl;
	}
	else {
		for(int i = inf; i <= sup; i++)
		{
			if (vetor[inf] == vetor[i] && inf != i) continue;
			iter_swap(vetor.begin()+inf,vetor.begin()+i);
			permuta(vetor, inf + 1, sup);
			iter_swap(vetor.begin()+inf,vetor.begin()+i); //backtracking
		}
	}
}

int main(int argc, char *argv[])
{
	int n;
	out.open("output.txt",std::fstream::out);
	std::string texto;
	std::cin >> n;
	while (n--){
		std::cin >> texto;
		std::sort(texto.begin(),texto.end());
		permuta(texto, 0,texto.size() - 1);
		out << std::endl;
	}
	out.close();
	return 0;
}
