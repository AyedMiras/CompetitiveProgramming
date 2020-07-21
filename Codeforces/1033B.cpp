#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int T;
ll a,b;

bool isPrime(ll n){
    if (n<2)
        return 0;
    if (n==2)
        return 1;
    for (ll i=3;i*i<=n;i+=2)
        if (n%i==0)
            return 0;
    return 1;
}

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << (a-b==1 && isPrime(a+b)?"YES":"NO") << endl;
    }
}
