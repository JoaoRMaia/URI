#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    string txt;
    while (T--)    {
        cin >> txt;        
        sort(txt.begin(), txt.end());
        do {
            cout << txt << "\n";
        } while (next_permutation(txt.begin(), txt.end()));
        cout << "\n";
    }
}
