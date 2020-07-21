#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n;

ll sumDigits(ll a){
    ll sum=0;
    while(a)
        sum+=a%10,a/=10;
    return sum;
}

int main() {
    cin >> n;
    ll i=10;
    while(n>=i)
        i*=10;
    cout << sumDigits(i/10-1)+sumDigits(n-i/10+1) << endl;
}

