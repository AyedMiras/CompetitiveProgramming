#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,a,b,c,res;

ll sum(ll k) {
    return (k*(k+1))/2 ;
}

int main() {
    cin >> n >> a >> b >> c;
    if (a<=b-c) res = n/a;
    else {
        res = (n-c)/(b-c);
        if (n < c) res =0;
        res +=(n- res*b + res*c)/a;
    }
    cout << res << endl;
}
