#include <iostream>
#include <vector>
using namespace std;

int main() {  
    int k;
    while (cin >> k) {
        vector<pair<int, int> > solutions;
        for (int y = k + 1; y <= 2 * k; ++y) {
            if ((k * y) % (y - k) == 0)
                solutions.push_back(make_pair((k * y) / (y - k), y));
        }
        cout << solutions.size() << endl;
        for (size_t i = 0; i < solutions.size(); ++i)
            cout << "1/" << k << " = 1/" << solutions[i].first << " + 1/" << solutions[i].second << endl;    
    }
    return 0;
}
