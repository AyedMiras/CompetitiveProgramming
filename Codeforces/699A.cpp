#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=200200;
int n,x[N],m=INF;
string s;

int main() {
    cin >> n >> s;
    for (int i=0;i<n;i++) cin >> x[i];
    for (int i=0;i<n-1;i++)
        if (s[i]=='R' && s[i+1]=='L')
            m=min(m,x[i+1]-x[i]);
    cout << (m==INF?-1:m/2) << endl;

}
