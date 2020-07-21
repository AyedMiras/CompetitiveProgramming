#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int P=10100;
const int Q=110;
const int INF=0x3f3f3f3f;
int T,p,q,pInd[Q];
map<pair<int,string>,ll> dp;

ll solve(int d, string r, set<int>& sR, set<int>& sL) {
    if (d==q)
        return 0;
    if (dp[make_pair(d,r)]!=0)
        return dp[make_pair(d,r)];
    dp[make_pair(d,r)]=INF;
    set<int> currS;
    for(set<int>::iterator it=sR.begin();it!=sR.end();++it)
        currS.insert(*it);
    for(set<int>::iterator it=currS.begin();it!=currS.end();++it) {
        r[*it]='1';
        ll indL=*(--sL.lower_bound(pInd[*it]));
        ll indR=*(sL.upper_bound(pInd[*it]));
        sL.insert(pInd[*it]);
        sR.erase(*it);
        ll res=solve(d+1,r,sR,sL)+indR-indL-2;
        sL.erase(pInd[*it]);
        sR.insert(*it);
        r[*it]='0';
        dp[make_pair(d,r)]=min(dp[make_pair(d,r)],res);
    }
    return dp[make_pair(d,r)];
}

int main() {
    scanf("%d",&T);
    while(T--) {
        dp.clear();
        scanf("%d%d",&p,&q);
        string released=string(q+2,'0');
        set<int> limitSet,releasedSet;
        limitSet.insert(0),limitSet.insert(p+1);
        for(int i=1;i<=q;i++)
            releasedSet.insert(i);
        for(int i=1;i<=q;i++)
            scanf("%d",&pInd[i]);
        printf("%lld\n",solve(0,released,releasedSet,limitSet));
    }
}
