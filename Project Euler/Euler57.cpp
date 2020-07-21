#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision
const int N=1000;
int128_t num=3,den=2,cnt;

bool gcd(ll a, ll b) {
    return !b?a:gcd(b,a%b);
}

int dig(ll n) {
    int d=0;
    while(n) {
        d++;
        n/=10;
    }
    return d;
}

int main() {
    for (int i=2;i<=100;i++) {
        //cout << gcd(num,den) << endl;
        ll aux=num;
        num = (2*den+num)/gcd(2*den+num,den+num);
        den = (den+aux)/gcd(2*den+aux,den+aux);
        cout << num << "/" << den << endl;
        if (dig(num)>dig(den)) cout << i << endl,cnt++;
    }
}
