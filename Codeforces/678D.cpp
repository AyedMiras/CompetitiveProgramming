#include <iostream>
#define MOD (int)(1e9 +7)
using namespace std;
long long int n;
long long int A,B,x;

long long int pow(long long int a, long long int n) {
    if (!n)
        return 1;
    long long int sqr_a = pow(a,n/2);
    if(n%2)
        return a*( (sqr_a*sqr_a)% MOD)% MOD;
    return (sqr_a*sqr_a)% MOD;
}
int main() {
    cin >> A >> B >> n >> x;
    if (!n)
        cout << x << endl;
    if (A==1)
        cout << (x +((n%MOD)*(B%MOD))%MOD)%MOD << endl;
    else
        cout << ( ( (pow(A,n)*x)%MOD) + B*( ( (pow(A,n) - 1)*pow(A-1,MOD-2) )%MOD )%MOD )%MOD << endl;
}
