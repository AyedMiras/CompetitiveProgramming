#include <bits/stdc++.h>
using namespace std;
const int N=10000010;
const int MOD=(int)1e9+7;
int n,dp[4][N];

int main() {
    cin >> n;
    dp[1][1]=dp[2][1]=dp[3][1]=1;
    for(int i=2;i<=n;i++) {
        dp[0][i]=((dp[1][i-1]+dp[2][i-1])%MOD+dp[3][i-1])%MOD;
        dp[1][i]=((dp[0][i-1]+dp[2][i-1])%MOD+dp[3][i-1])%MOD;
        dp[2][i]=((dp[0][i-1]+dp[1][i-1])%MOD+dp[3][i-1])%MOD;
        dp[3][i]=((dp[0][i-1]+dp[1][i-1])%MOD+dp[2][i-1])%MOD;
    }
    cout << dp[0][n] << endl;
}

