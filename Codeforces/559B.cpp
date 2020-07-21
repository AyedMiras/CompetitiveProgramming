#include <bits/stdc++.h>
using namespace std;
const int N=200200;
string s1,s2;

bool isEquiv(string a, string b) {
    int l1 = a.length(),l2=b.length();
    string a1 = a.substr(0,l1/2),a2 = a.substr(l1/2),b1=b.substr(0,l2/2),b2=b.substr(l2/2);
    //cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    if (!strcmp(a1.c_str(),b1.c_str()) && !strcmp(a2.c_str(),b2.c_str()))
        return 1;
    if (!strcmp(a2.c_str(),b1.c_str()) && !strcmp(a1.c_str(),b2.c_str()))
        return 1;
    if (a1.length()&1 || a2.length()&1 || b1.length()&1 || b2.length()&1)
        return 0;
    return ( (isEquiv(a1,b1) && isEquiv(a2,b2) ) || (isEquiv(a2,b1) && isEquiv(a1,b2)) );
}

int main() {
    ios::sync_with_stdio(0);
    cin >> s1 >> s2;
    if (s1.length()!=s2.length())
        return 0*printf("NO\n");
    if (!strcmp(s1.c_str(),s2.c_str()))
        return 0*printf("YES\n");
    if (s1.length()&1)
        return 0*printf("NO\n");
    cout << (isEquiv(s1,s2)?"YES":"NO") << endl;
}
