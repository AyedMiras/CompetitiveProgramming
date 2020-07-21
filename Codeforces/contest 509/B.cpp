#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll a,b,x,y,g;

ll gcd(ll i, ll j) {
    return (!j?i:gcd(j,i%j));
}


int main() {
    cin >> a >> b >> x >> y;
    g = gcd(x,y);
    cout << min(a/(x/g),b/(y/g)) << endl;
}
