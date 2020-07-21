#include <bits/stdc++.h>
using namespace std;
int T;
long long int a,b;

bool isPrime(long long int n){
    if (n==2) return 1;
    if (n<2) return 0;
    for (long long int i=3;i*i<n;i+=2)
        if (n%i==0)
            return 0;
    return 1;
}

int main() {
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << (a-b==1 && isPrime(a+b)?"YES":"NO") << endl;
    }
}
