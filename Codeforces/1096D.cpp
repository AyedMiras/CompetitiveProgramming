#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
ll n,a[N],dp[N][5];
string s;
map<int,char> m;

ll solve(int i, int j) {
    if (i==-1){
        return 0;
    }
    if (dp[i][j]!=-1)
        return dp[i][j];
    if (j>=3){
        if (s[i]=='h')
            return dp[i][j]=solve(i-1,j)+a[i];
        return dp[i][j]=solve(i-1,j);
    }
    if (s[i]==m[j+1])
        return dp[i][j]=min(solve(i-1,j)+a[i],solve(i-1,j+1));
    return dp[i][j]=solve(i-1,j);
}

void init() {
    memset(dp,-1,sizeof(dp));
    m[1]='d';
    m[2]='r';
    m[3]='a';
    m[4]='h';
}

int main() {
    init();
    cin >> n >> s;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << solve(n-1,0)<< endl;
}
