#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m,k;

ll gcd(ll a, ll b){
    return !b?a:gcd(b,a%b);
}

int main() {
    cin >> n >> m >> k;
    int a=n,b=m;
    int g=gcd(n,k);
    a/=g,k/=g;
    g = gcd(m,k);
    b/=g,k/=g;
    if (k>2)
        return 0*printf("NO\n");
    cout << "YES" << endl;
    if (k==1) {
        if (2*a<=n)
            a*=2;
        else
            b*=2;
    }
    cout << "0 0" << endl;
    cout << "0 " << b << endl;
    cout << a << " 0" << endl;
}

