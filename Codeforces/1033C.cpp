#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,a[N],dp[N];

int solve(int ind){
    if (dp[ind]!=-1)
        return dp[ind];
    dp[ind]=1;
    for (int i=ind+a[ind];i<=n;i+=a[ind])
        if (a[i]>a[ind])
            dp[ind]&=solve(i);
    for (int i=ind-a[ind];i>0;i-=a[ind])
        if (a[i]>a[ind])
            dp[ind]&=solve(i);
    return dp[ind]=(1-dp[ind]);
}

int main() {
    ios::sync_with_stdio(0);
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=n;i++)
        cout << (solve(i)?"A":"B");
    cout << endl;
}
