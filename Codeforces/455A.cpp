#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n,a[N];
long long int dp[2][N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    dp[1][0] = a[0];
    for (int i=1;i<n;i++) {
        if (a[i] == a[i-1]+1) {
            dp[1][i] = dp[0][i-1] + a[i];
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
        }
        else if (a[i]==a[i-1]) {
            dp[1][i] = dp[1][i-1] + a[i];
            dp[0][i] = dp[0][i-1];
        }
        else {
            dp[1][i] = max(dp[1][i-1],dp[0][i-1]) + a[i];
            dp[0][i] = max(dp[1][i-1],dp[0][i-1]);
        }
    }
    cout << max(dp[1][n-1],dp[0][n-1]) << endl;
}
