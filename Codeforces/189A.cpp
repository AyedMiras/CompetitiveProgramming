#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n,a,b,c;
  int dp[4010];
  memset(dp,-1,sizeof(dp));
  cin >> n >> a >> b >> c;
  dp[0] = 0;
  for (int i=min(a,min(b,c));i<=n;i++){
    int arg1,arg2,arg3;
    arg1 = (i >= a)? dp[i-a]: -1;
    arg2 = (i >= b)? dp[i-b]: -1;
    arg3 = (i >= c)? dp[i-c]: -1;
    dp[i] = max(arg1,max(arg2,arg3));
    if (dp[i]!= -1) dp[i]++;
  }
  cout << dp[n] << endl; // substract one



  return 0;
}
