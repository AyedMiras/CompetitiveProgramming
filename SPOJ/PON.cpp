#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int T;
ll num;

ll modmul(ll a, ll b, ll p) {
    ll res = 0;
    a=a%p;
    while(b) {
        if (b&1) res = (a+res)%p;
        a = (a<<1)%p;
        b>>=1;
    }
    return res;
}

ll modexp(ll a, ll b, ll p) {
    ll res = 1;
    a = a%p;
    while(b){
        if (b&1) res = modmul(res,a,p);
        a = modmul(a,a,p);
        b>>=1;
    }
    return res;
}

bool miller(ll a,ll n) {
    if (n<2) return 0;
    if (n==2) return 1;
    if (!(n&1)) return 0;
    ll d = n-1;
    while(!(d&1)) d>>=1;
    //ll a = rand()%(n-1)+1;
    ll x =modexp(a,d,n);
    while(d!=n-1 && x!=1 && x!=n-1) {
        x = modmul(x,x,n);
        d<<=1;
    }
    if (x!=n-1 && !(d&1)) return 0;
    return 1;
}

bool isPrime(ll n) {
    int base[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int i=0;i<12;i++)
        if (n!=base[i] && !miller(base[i],n)) return 0;
    return 1;
}


int main() {
    ios::sync_with_stdio(0);
    //cout << modmul(5,20,70) << " " << modexp(10000,3,100);
    cin >> T;
    while(T--) {
        cin >> num;
        cout << (isPrime(num)?"YES":"NO") << endl;
    }
}
