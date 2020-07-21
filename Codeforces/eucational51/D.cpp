#include <bits/stdc++.h>
using namespace std;
const int N=1010;
long long int n,K,dp[N][2*N][5],MOD=998244353;
map<string,int> mask;

void init(){
    mask["00"]=0;
    mask["01"]=1;
    mask["10"]=2;
    mask["11"]=3;
}

int main() {
    init();
    cin >> n >> K;
    dp[1][1][mask["00"]]=1;
    dp[1][2][mask["01"]]=1;
    dp[1][1][mask["11"]]=1;
    dp[1][2][mask["10"]]=1;
    for (int i=2;i<=n;i++){
        for (int k=1;k<=2*i;k++){
            dp[i][k][mask["00"]]=dp[i-1][k][mask["00"]]+dp[i-1][k][mask["01"]]
                +dp[i-1][k][mask["10"]]+(k>1?dp[i-1][k-1][mask["11"]]:0);

            dp[i][k][mask["01"]]=(k>1?dp[i-1][k-1][mask["00"]]:0)+dp[i-1][k][mask["01"]]
                +(k>3?dp[i-1][k-2][mask["10"]]:0)+(k>1?dp[i-1][k-1][mask["11"]]:0);

            dp[i][k][mask["10"]]=(k>1?dp[i-1][k-1][mask["00"]]:0)+(k>3?dp[i-1][k-2][mask["01"]]:0)
                +dp[i-1][k][mask["10"]]+(k>1?dp[i-1][k-1][mask["11"]]:0);

            dp[i][k][mask["11"]]=(k>1?dp[i-1][k-1][mask["00"]]:0)+dp[i-1][k][mask["01"]]
                +dp[i-1][k][mask["10"]]+dp[i-1][k][mask["11"]];

            dp[i][k][mask["00"]]%=MOD;
            dp[i][k][mask["01"]]%=MOD;
            dp[i][k][mask["10"]]%=MOD;
            dp[i][k][mask["11"]]%=MOD;
        }
    }
    long long int res=
        dp[n][K][mask["00"]]+dp[n][K][mask["01"]]+dp[n][K][mask["10"]]+dp[n][K][mask["11"]];
    cout << res%MOD << endl;
}
