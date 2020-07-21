#include <bits/stdc++.h>
using namespace std;
string s;
int n;

int main() {
    cin >> s;
    n = 1<<s.length();
    int j =1;
    for (int i=s.length()-1;i>=0;i--)
        n+= (s[i]=='7'?j:0),j*=2;
    cout << n-1 << endl;
}
