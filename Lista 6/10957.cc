#include <iostream>
#include <vector>
#include <string>


int solucoes;

template<typename T>
bool isValid(T& sodocu, int c, std::pair<int,int> pos){
	
	for ( int i = 0 ; i < 9 ; i++) if ( sodocu[pos.first][i] == c && i != pos.second) {
		//std::cout << "Bateu pq c = " << c << " e posicoes " << pos.first << " " << pos.second << " com valores " <<  sodocu[pos.first][i] << " e " << sodocu[i][pos.second] << std::endl;
	return false;  // linha coluna
	}
	
	for ( int i = 0 ; i < 9 ; i++) if ( sodocu[i][pos.second] == c && i != pos.first ) {
		//std::cout << "Bateu pq c = " << c << " e posicoes " << pos.first << " " << pos.second << " com valores " <<  sodocu[pos.first][i] << " e " << sodocu[i][pos.second] << std::endl;
	return false;  // linha coluna
	}
	
	std::pair<int,int> quad{(pos.first/3)*3,(pos.second/3)*3};
	//std::cout << "quadfirst " << quad.first << " sec " << quad.second << std::endl;
	for ( int i = quad.first ; i < quad.first+3 ; i++) {
		for (int j = quad.second ; j < quad.second+3 ; j++) {
			if (sodocu[i][j] == c && !(i == pos.first && j == pos.second)) {
				//std::cout << "Bateu pq c = " << c << " e existe um " << sodocu[i][j]<< "  nas celulas" << i << " e " << j << std::endl;
				//std::cout << "quebrou pelo quadrante" << std::endl;
				return false;
			}
		}
	}
	return true;
}

template<typename T>
int leSodocu(T& sodocu){
	char input;
	int valido = 1;
	input = getchar();
	if (input=='\n') return 0; // 0 = parou
	else ungetc((int)input,stdin);
	
	for ( int i = 0 ; i < 9 ; i++)
		for ( int j = 0 ; j < 9 ; j++) {
			std::cin >> sodocu[i][j]; 
			if (sodocu[i][j] == 0) continue;
			else if (!isValid(sodocu,sodocu[i][j],std::pair<int,int>{i,j})) valido = -1;
		}
	//std::cout << "Terminei de ler" << std::endl;
	return valido;
}
template<typename T>
void imprimeSodocu(T& sodocu){
	int num;
	for ( int i = 0 ; i < 9 ; i++) {
		for ( int j = 0 ; j < 9 ; j++) {
			std::cout << sodocu[i][j] << " ";
		}
		std::cout << "\n";
	}
}


template<typename T>
void resolveSodocu(T& sodocu, int lin, int col){
	std::cout << "Entrei no resolve sudoku com lin =" << lin << " e col = " << col << std::endl;
	std::cout << "Como esta o sudoku" << std::endl;
	imprimeSodocu(sodocu);
	if (solucoes >= 2) return;
	
	for ( int i = lin ; i < 9 ; i++) {
		for ( int j = col ; j < 9 ; j++){
			if (sodocu[i][j]) continue;
			else {
				for(int k = 1 ; k <= 9 ; k++) {
					if (isValid(sodocu,k,std::pair<int,int>{i,j})){
						sodocu[i][j]= k;
						std::cout << "inserido o " << k << " na posicao: " << i << " " << j << std::endl;
						if (j+1 == 9) resolveSodocu(sodocu,i+1,0);
						else resolveSodocu(sodocu,i,j+1);
						sodocu[i][j]= 0;
					}
				}
			return;
			}
		}
	}
	imprimeSodocu(sodocu);
	solucoes++;
	std::cout << "Sai do resolve sudoku com lin =" << lin << " e col = " << col << std::endl;
}
int main () {
	std::vector<std::vector<int>> sodocu(9,std::vector<int>(9));
	int opcode;
	
	do {
		opcode = leSodocu(sodocu);
		solucoes = 0;
		if (opcode == -1) std::cout<<"Illegal"<< std::endl;
		else if (opcode) {
			resolveSodocu(sodocu,0,0);
			std::cout <<"Existem " << solucoes << " solucoes " << std::endl;
			if (!solucoes) std::cout << "Impossible" << std::endl;
			else if (solucoes == 2) std::cout << "Ambiguous" << std::endl;
			else std::cout << "Unique" << std::endl;
		}
	}while (opcode);
		
	return 0;
}
