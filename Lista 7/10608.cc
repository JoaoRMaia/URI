#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main () {
	
	int n,amg,con;
	int a1, a2;
	int max_e, count;
	cin >> n;
	map<int,int> conhecidos;
	while (n--){
		cin >> amg >> con;
		for (int i = 1 ; i <= amg ; i++){
			conhecidos.insert(pair<int,int>{i,0});  
		}
		for (int i = 0 ; i < con ; i++){
			cin >> a1 >> a2;
			while (conhecidos[a1] != 0) {
				a1 = conhecidos[a1];
			}
			conhecidos[a2] = a1;			
		}
		max_e = 0;
		for (int i = 1 ; i <= amg ; i++){
			if (conhecidos[i] != 0) continue;
			count = 1;
			for (int j = 1 ; j <= amg ; j++) if (conhecidos[j] == i) count++;
			max_e = max(count,max_e);
		}
		for (int i = 1 ; i <= amg ; i++){
			while (conhecidos[i] != 0 && conhecidos[conhecidos[i]] != 0 )
			cout << "vou trocar " << conhecidos[i] << " por " << conhecidos[conhecidos[i]] << endl;
				conhecidos[i] = conhecidos[conhecidos[i]];
		}
		for (int i = 1 ; i <= amg ; i++){
			cout << "Amigo n " << i << " conhece o " << conhecidos[i] << endl;  
		}
		conhecidos.clear();
		cout << "num max = " << max_e << endl;
		
		
		
		
	}
	return 0;
}
