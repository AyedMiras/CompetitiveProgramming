#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
    cin >> n >> s;
    int i=s.length()-2;
    for (;i>=0;i-=2)
        cout << s[i];
    i=(i%2)+1;
    for (;i<s.length();i+=2)
        cout << s[i];
    cout << endl;
}
