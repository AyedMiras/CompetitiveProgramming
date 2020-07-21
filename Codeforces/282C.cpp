#include <bits/stdc++.h>
using namespace std;
string a,b;

int main() {
    cin >> a >> b;
    if (a.length()!=b.length()) {
        cout << "NO" << endl;
        return 0;
    }
    bool flag = true;
    for (int i=0;i<a.length()-1;i++) {
        if (a[i]==b[i]) continue;
        if (a[i]=='1') {
            if (a[i+1]=='1') a[i]='0',a[i+1]='1';
            else {flag=false; break;}
        }
        else {
            if (a[i+1]=='0')
        }

    }
}
