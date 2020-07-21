#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 100100;
const int MAX = 1000100;
int n;
ll x[N];
bool sieve[MAX];

void eras() {
    for (int i=2;i<=MAX;i++) {
        if (!sieve[i]) {
            for (int j=2;i*j<=MAX;j++)
                sieve[i*j]=true;
        }
    }
}

int main() {
    cin >> n;
    eras();
    for (int i=0;i<n;i++) {
        cin >> x[i];
        if ( x[i]!=1 && (ll)sqrt(x[i])*(ll)sqrt(x[i])==x[i] && !sieve[(int)sqrt(x[i])])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
