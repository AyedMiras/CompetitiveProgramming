#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9+7;
int n,k,dp[2020][2020];

int main() {
    cin >> n >> k;
    for (int i=1;i<=n;i++) dp[i][1]=1;
    for (int j=2;j<=k;j++) {
        for (int i=1;i<=n;i++) {
            for (int k=1;k*i<=n;k++) {
                dp[i*k][j]=((dp[i][j-1]%MOD)+dp[i*k][j])%MOD;
            }
        }
    }
    int s=0;
    for (int i=1;i<=n;i++) {
        s=(s+dp[i][k])%MOD;
    }
    cout << s << endl;
}
