#include <bits/stdc++.h>
using namespace std;
string s;
int n,k;

int main() {
    cin >> s >> k;
    n = s.length();
    int cnt=0;
    for (int i=n-1;i>=0;i--) {
        if (s[i]=='0') k--;
        else cnt++;
        if (!k) break;
    }
    if (!k) cout << cnt << endl;
    else cout << n-1 << endl;

}
