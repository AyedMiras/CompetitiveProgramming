#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    for (int i=0;s[i];i++) {
        if (!i && s[i]=='9') continue;
        if ('9'-s[i] <= s[i]-'0') s[i] = '9'-s[i]+'0';
    }
    cout << s << endl;
}
