#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m;
map<string,string> name;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        string s1,s2;
        cin >> s1 >> s2;
        name[s2]=s1;
    }
    for (int i=0;i<m;i++) {
        string s1,s2;
        cin >> s1 >> s2;
        cout << s1 << " " << s2 << " " << "#" << name[s2.substr(0,s2.size()-1)] << endl;
    }
}
