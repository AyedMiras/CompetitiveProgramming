#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll MOD=998244353;
ll n,indl,indr;
string s;
char l,r;

int main() {
    cin >> n >> s;
    if (n==1)
        return cout << 1 << endl,0;
    l=s[0],r=s[n-1];
    indl=0,indr=n-1;
    for (int i=1;i<n;i++) {
        if (s[i]==l)
            indl++;
        else
            break;
    }
    if (indl==n-1)
        return cout << ((n*(n+1))/2)%MOD << endl,0;
    for (int j=n-2;j>=0;j--) {
        if (s[j]==r)
            indr--;
        else
            break;
    }
    ll cnt = n-indr+1+indl;
    if (l==r) {
        cnt+=(indl+1)*(n-indr);
    }
    cout << (cnt+1)%MOD << endl;
}
