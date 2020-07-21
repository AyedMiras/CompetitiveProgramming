#include <bits/stdc++.h>
using namespace std;
int n;

bool isPrime(int i) {
    if (i%2 == 0) return 0;
    for (int j=3;j*j<=i;j+=2) {
        if (i%j==0) return 0;
    }
    return 1;
}

int main() {
    cin >> n;
    if (n==2 || n==3 || n==5) cout << 1 << endl;
    else if (n==4) cout << 2 << endl;
    else if (n%2 ==0) cout << 2 << endl;
    else if (isPrime(n)) cout << 1 << endl;
    else if (isPrime(n-2)) cout << 2 << endl;
    else cout << 3 << endl;
}
