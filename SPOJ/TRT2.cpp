#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int const MAXN=2e3+50;
ll a[MAXN];
ll dp[MAXN][MAXN];
int n;

ll solve (int i,int j){
    if (i>j) return 0;
    ll &ret=dp[i][j];
    if (~ret) return ret;
    ll days=i+n-j;
    return ret=max(a[i]*days+solve(i+1,j),a[j]*days+solve(i,j-1));
}

int main (){
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i=0;i<n;i++)
        cin >> a[i];
    cout<<solve(0,n-1);

}



