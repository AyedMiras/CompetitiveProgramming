#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MOD = (int)1e9;
int n,m;
ll a[1010],b[1010];

ll gcd(ll x, ll y) {
    if (!y) return x;
    if (y>x) return gcd(y,x);
    return  gcd(y,x%y);
}

int main() {

    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++) cin >> b[i];
    long long int ans = 1LL;
    bool flag = false;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            ans*=gcd(a[i],b[j]);
            if (ans > MOD) ans%=MOD,flag = true;
        }
    }
    if(flag)
    {
        if(ans<10) printf("00000000");
        else if(ans<100) printf("0000000");
        else if(ans<1000) printf("000000");
        else if(ans<10000) printf("00000");
        else if(ans<100000) printf("0000");
        else if(ans<1000000) printf("000");
        else if(ans<10000000) printf("00");
        else if(ans<100000000) printf("0");
    }
    cout << ans << endl;

}
