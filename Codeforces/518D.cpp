#include <bits/stdc++.h>
using namespace std;
const int N=2020;
int n,t;
double p,dp[N][N];

int main() {
    cin >> n >> p >> t;
    dp[n][0]=1;
    for(int i=n;i>0;i--)
        for(int j=1;j<=t+1;j++)
            dp[i][j]=dp[i][j-1]*(1-p)+dp[i+1][j-1]*p;
    double res=0;
    for(int i=1;i<=n;i++)
        res+=i*dp[i][t];
    cout << setprecision(12) << n-res << endl;
}
