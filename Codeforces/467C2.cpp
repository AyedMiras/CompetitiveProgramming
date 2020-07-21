#include <bits/stdc++.h>
using namespace std;

int n,m,k;
long long int p[5005],cum[5005],dp[5005][5005];

int main() {
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) cin >> p[i],cum[i] = p[i] + cum[i-1];
    dp[1][m] = cum[m];
    for (int i=1;i<=k;i++) {
        for (int j=m+1;j<=n;j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-m] + cum[j] - cum[j-m]);
        }
    }
    cout << dp[k][n] << endl;
}
