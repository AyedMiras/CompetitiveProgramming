#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
const int MOD=(int)1e9+7;
ll n,a[N],cnt[N],ans;
vector<ll> d[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=1;j*j<=a[i];j++) {
            if (a[i]%j==0 && j<=i+1) {
                d[i].push_back(j);
                if (j*j!=a[i] && a[i]/j<=i+1) {
                    d[i].push_back(a[i]/j);
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<d[i].size();j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<d[i].size();j++) {
            ans+=cnt[d[i][j]-1];
            ans%=MOD;
        }
        for (int j=0;j<d[i].size();j++)
            cnt[d[i][j]]++;
        ans++;
    }
    cout << ans%MOD << endl;
}
