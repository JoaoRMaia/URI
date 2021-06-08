#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

int main () {
	ofstream out; 
	out.open("output.txt"); 
	int m = 1,n = 1;
	
	while (1) {
		cin >> m >> n;
		if ( m == 0 && n == 0) break;
		else if ( m == 0 or n == 0) out << "0 knights may be placed on a " << m << " row " << n << " column board." << endl;
		else if ( m == 1 or n == 1) out << m*n << " knights may be placed on a " << m << " row " << n << " column board." << endl;
		else if ( m == 2 or n == 2) out << (m*n/8)*4 + min((m*n%8),4) <<" knights may be placed on a " << m << " row " << n << " column board." << endl;
		else out << ceil((float) m*n/2) <<" knights may be placed on a " << m << " row " << n << " column board." << endl;
	}
	
	
	out.close();
	return 0;
}
