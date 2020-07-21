#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=1010;
ll T,H,A,dp[2*N][2*N][3];
map<int,pair<int,int>> m;

ll solve(ll h, ll a, int pos) {
    h+=m[pos].first,a+=m[pos].second;
    if (h<=0 || a<=0)
        return 0;
    if (dp[h][a][pos]!=-1)
        return dp[h][a][pos];
    return dp[h][a][pos]=max(solve(h,a,(pos+1)%3),solve(h,a,(pos+2)%3))+1;
}

void init() {
    m[0]=make_pair(3,2);
    m[1]=make_pair(-5,-10);
    m[2]=make_pair(-20,5);
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin >> T;
    while(T--){
        memset(dp,-1,sizeof(dp));
        cin >> H >> A;
        cout << max(max(solve(H,A,0),solve(H,A,1)),solve(H,A,2)) << endl;
    }
}
