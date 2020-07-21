#include <bits/stdc++.h>
using namespace std;
int n,l,d;
map<pair<int,int>,int> dp;
stack<int> res;

int solve(int c, int num, int flag) {
    if(c==n-1) {
        if(num>=1 && num<=l) {
            res.push(num);
            return dp[make_pair(c,num)]=1;
        }
        return dp[make_pair(c,num)]=-1;
    }
    if (num>5000 || num<-5000)
        return dp[make_pair(c,num)]=-1;
    if(dp[make_pair(c,num)]==-1)
        return -1;
    for(int i=(flag?1:l);(flag?i<=l:i>=1);(flag?i++:i--)) {
        if(solve(c+1,i-num,1-flag)==1) {
            res.push(i);
            return  dp[make_pair(c,num)]=1;
        }
    }
    return dp[make_pair(c,num)]=-1;
}

int main() {
    cin >> n >> d >> l;
    if (solve(0,d,d<=0)==1) {
        cout << res.top();
        res.pop();
        while(!res.empty()) {
            cout << " " << res.top();
            res.pop();
        }
    }
    else
        cout << -1 << endl;
}
