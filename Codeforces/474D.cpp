#include <bits/stdc++.h>
using namespace std;
const int MOD =(int)1e9+7;
const int N = 100100;
int T,k,a,b,dp[N],cum[N];

void init() {
    for (int i=0;i<k;i++) dp[i] = 1;
    for (int i=k;i<N;i++) {
        dp[i] = (dp[i-1]+dp[i-k])%MOD;
    }
    for (int i=1;i<N;i++) cum[i] = (cum[i-1]+dp[i])%MOD;
}

int main() {
    cin >> T >> k;
    init();
    while(T--) {
        cin >> a >> b;
        int res = cum[b]-cum[a-1];
        cout << (res>=0?res:res+MOD)<< endl;
    }
}
