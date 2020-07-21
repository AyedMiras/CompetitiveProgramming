#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1010;
const int MOD=(int)1e6+3;
ll n,dp[N],twoPow[2*N];

void init() {
    twoPow[0]=1;
    for(int i=1;i<=2*N;i++)
        twoPow[i]=(twoPow[i-1]*2)%MOD;
    memset(dp,-1,sizeof(dp));
}

ll cookie(ll a) {
    return (twoPow[a-1]*(twoPow[a]+1))%MOD;
}

ll solve(ll a) {
    if (a<=0)
        return 0;
    if (dp[a]!=-1)
        return dp[a];
    dp[a]=cookie(a)%MOD;
    for(int i=1;a-i>0;i++) {
        dp[a]=(dp[a]+solve(a-i)*twoPow[i-1])%MOD;
    }
    return dp[a];
}

int main() {
    init();
    cin >> n;
    cout << (twoPow[2*n]-solve(n)+MOD)%MOD << endl;
}
