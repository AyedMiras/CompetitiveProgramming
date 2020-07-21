#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,dp[N];
pair<int,int> c[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> c[i].first >> c[i].second;
    sort(c,c+n);
    dp[0]=0;
    for (int i=1;i<n;i++) {
        int l = lower_bound(c,c+i,make_pair(c[i].first-c[i].second,0)) - c;
        dp[i] = i-l + (l?dp[l-1]:0);
    }
    int res=n;
    for (int i=0;i<n;i++)
        res = min(res,n-i-1+dp[i]);
    cout << res << endl;
}
