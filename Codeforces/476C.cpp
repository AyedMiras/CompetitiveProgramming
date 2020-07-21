#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long int a,b,res;

long long int sum(long long int x) {
    return (x*(x+1))/2 %MOD;
}

int main() {
    cin >> a >> b;
    cout << ((sum(b-1)%MOD )* ((b*sum(a) + a)%MOD) ) % MOD << endl;
}
