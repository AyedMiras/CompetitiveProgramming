#include <bits/stdc++.h>
using namespace std;
string s;
map<char,int> occ;

bool isPrime(int n) {
    if (n==2) return 1;
    for (int i=3;i*i<=n;i+=2) {
        if (n%i==0)
            return 0;
    }
    return 1;
}

int main(){
    cin >> s;
    for (int i=0;s[i];i++)
        occ[s[i]]++;
    if (s.size()<4 || occ.size()==1) {
        cout << "YES" << endl << s << endl;
        return 0;
    }
    if (occ.size()>2)
        return 0*printf("NO\n");
    if (occ.begin()->second != s.size()-1 && occ.begin()->second !=1)
        return 0*printf("NO\n");
    if (!isPrime(s.size()))
        return 0*printf("NO\n");
    cout << "YES" << endl;
    if (occ.begin()->second == 1) {
        for (int i=0;i<s.size()-1;i++)
            cout << (++occ.begin())->first;
        cout << occ.begin()->first << endl;
    }
    else {
        for (int i=0;i<s.size()-1;i++)
            cout << occ.begin()->first;
        cout << (++occ.begin())->first << endl;
    }
}
