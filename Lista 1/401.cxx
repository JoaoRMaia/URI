#include <iostream>
#include <string>

using namespace std;
int main() {
	int i,j;
    string input = " ";
    string rev = "A   3  HIL JM O   2TUVWXY5";
    string esp = "01SE Z  8 ";
    bool reverse, mirrored;
    while(1) {
		getline(cin,input);
		if (input[0] == '\0') break;
        reverse = false;
        mirrored = false;
        for(i = 0, j = input.size()-1; i <= j; i++, j--) {
            if(input[i] != input[j])
                reverse = true;
            if(input[i] >= 'A' && input[i] <= 'Z') {
                if(input[j] != rev[input[i]-'A'])
                    mirrored = true;
            } else {
                if(input[j] != esp[input[i]-'0'])
                    mirrored = true;
            }
        }
       cout << input << " -- is ";
        if(reverse) {
            if(mirrored)
                cout << "not a palindrome." << endl;
            else
                cout << "a mirrored string." << endl;
        } else {
            if(mirrored)
                cout << "a regular palindrome." << endl;
            else
                cout << "a mirrored palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}
