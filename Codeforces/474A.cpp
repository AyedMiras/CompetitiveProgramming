#include <bits/stdc++.h>
using namespace std;

map<char,char> m[2];
string keyboard[3] = {"qwertyuiop","asdfghjkl;","zxcvbnm,./"},input;
char shift;

void init() {
    int n= keyboard[0].length();
    for (int j=0;j<3;j++) {
        for (int i=0;i<n;i++) {
            m[0][keyboard[j][i]]=(i+1<n?keyboard[j][i+1]:-1);
            m[1][keyboard[j][i]]=(i-1>=0?keyboard[j][i-1]:-1);
        }
    }
}

int main() {
    init();
    cin >> shift >> input;
    for (int i=0;input[i];i++)
        cout << m[shift=='R'][input[i]];
    cout << endl;

}
