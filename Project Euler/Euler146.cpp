#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=150000000;
const int M=2000;
int sieve[M],ind[6]={1,3,7,9,13,27};
vector<int> primes;
ll s;

void eras() {
    for (int i=2;i<M;i++){
        if (!sieve[i]) {
            for (int j=2;i*j<M;j++)
                sieve[i*j]=1;
            primes.push_back(i);
        }
    }
}

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

int miller(int base,ll n) {
    ll d = n-1;
    while(!(d&1)) d>>=1;
    ll a = base;
    ll x =modexp(a,d,n);
    while(d!=n-1 && x!=1 && x!=n-1) {
        x = modmul(x,x,n);
        d<<=1;
    }
    if (x!=n-1 && !(d&1)) return 0;
    return 1;
}

int isValid(ll n) {
    int basePrimes[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int i=0;i<primes.size();i++)
        for(int j=0;j<6;j++)
            if ( (n+ind[j])%primes[i]==0)
                return 0;
    for (int j=0;j<6;j++)
        for (int i=0;i<12;i++)
            if (!miller(basePrimes[i],n+ind[j]))
                return 0;
    for (int i=0;i<12;i++)
        if (!miller(basePrimes[i],n+19) && !miller(basePrimes[i],n+21)) return 1;
    return 0;
}

int isValidBase2(ll n) {
    for (int i=0;i<primes.size();i++)
        for(int j=0;j<6;j++)
            if ( (n+ind[j])%primes[i]==0)
                return 0;
    for (int j=0;j<6;j++)
            if (!miller(2,n+ind[j]))
                return 0;
    if (!miller(2,n+19) && !miller(2,n+21)) return 1;
    return 0;
}

int main() {
    eras();
    for (int i=10;i<N;i+=10) {
        ll n = (ll)i*i;
        if ((i%210==10 || i%210==80 || i%210==130 || i%210==200 ) && isValidBase2(n))
        s+=i;
    }
    cout << s << endl;
}
