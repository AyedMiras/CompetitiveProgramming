#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int T;
ll a,b;

int main() {
    cin >> T;
    while(T--) {
        cin >> a >> b;
        ll res = 1;
        while(b) {
            if (b&1) res= (res*a)%10;
            a=(a*a)%10;
            b>>=1;
        }
        cout << res << endl;
    }
}
