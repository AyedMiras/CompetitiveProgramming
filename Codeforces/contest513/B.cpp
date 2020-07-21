#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;

ll sum(ll a){
    ll s=0;
    while(a){
        s+=a%10;
        a=a/10;
    }
    return s;
}


int main() {
    cin >> n;
    ll base=10;
    while(n>=base)
        base*=10;
    cout << sum(base/10-1) + sum(n-base/10+1) << endl;
}
