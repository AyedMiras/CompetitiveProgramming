#include <bits/stdc++.h>
using namespace std;
int T;
char op;
string s;
map<string,int> a;

string m4p(string ss) {
    string res;
    for (int i=0;ss[i];i++)
        res+= ((ss[i]-'0')&1)+'0';
    int i=0;
    for (;res[i];i++)
        if (res[i]-'0') break;
    //cout << res.substr(i) << endl;
    if (res.substr(i).empty()) return "0";
    return res.substr(i);
}

int main() {
    cin >> T;
    while(T--) {
        cin >> op >> s;
        s = m4p(s);
        if (op=='+') a[s]++;
        if (op=='-') a[s]--;
        if (op=='?') cout << a[s] << endl;
    }
}
