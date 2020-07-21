#include <bits/stdc++.h>
using namespace std;
string s,t;

int main() {
    cin >> s >> t;
    cout << max(fabs(s[0]-t[0]) , fabs(s[1]-t[1])) << endl;
    while(s[0]!=t[0] || s[1]!=t[1]) {
        if (s[0]<t[0])
            cout << "R",s[0]++;
        else if (s[0] > t[0])
            cout << "L",s[0]--;
        if (s[1]<t[1])
            cout << "U",s[1]++;
        else if (s[1]>t[1])
            cout << "D",s[1]--;
        cout << endl;
    }
}
