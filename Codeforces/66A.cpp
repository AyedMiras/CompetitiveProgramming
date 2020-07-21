#include <bits/stdc++.h>
using namespace std;
string s,c[4][2]={{"-128","127"},{"-32768","32767"},{"-2147483648","2147483647"},{"-9223372036854775808","9223372036854775807"}},
    out[5]={"byte","short","int","long","BigInteger"};
bool flag;

int main() {
    cin >> s;
    for (int i=0;i<4;i++) {
        if (s.length() < c[i][1].length()+(s[0]=='-') ||
            s.length()== c[i][1].length()+(s[0]=='-') && s.compare(c[i][s[0]!='-'])<=0) {
            cout << out[i];
            flag = true;
            break;
        }
    }
    if (!flag) cout << out[4];
    cout << endl;
}
