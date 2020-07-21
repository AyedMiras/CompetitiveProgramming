#include <bits/stdc++.h>
#define ll long long int
#define INF 0x3f3f3f3f
using namespace std;
const int H=200;
ll T,hours,energy,sleep,drinkCount,drink,crash;
pair<ll,ll> problem[H];
map<tuple<int,ll,int,int>,ll> dp;

ll solve(int h,ll e,int dc,int crashTime) {
    if (h==hours)
        return 0;
    if (dp.find(make_tuple(h,e,dc,crashTime))!=dp.end())
        return dp[make_tuple(h,e,dc,crashTime)];
    if (crashTime!=-1 && crashTime==h-2)
        return dp[make_tuple(h,e,dc,crashTime)]=solve(h,e-crash,dc,-1);
    if (h>=hours-2 && dc && e+drink>=problem[h].first)
        return dp[make_tuple(h,e,dc,crashTime)]=solve(h+1,e+drink-problem[h].first,dc-1,h)+problem[h].second;
    if (h==hours-1 && e>=problem[h].first)
        return dp[make_tuple(h,e,dc,crashTime)]=solve(h+1,e-problem[h].first,dc,(crashTime!=-1?crashTime+1:-1))+problem[h].second;
    dp[make_tuple(h,e,dc,crashTime)]=-INF;
    if (dc && e+drink>=problem[h].first)
        dp[make_tuple(h,e,dc,crashTime)]=max(dp[make_tuple(h,e,dc,crashTime)],solve(h+1,e+drink-problem[h].first,dc-1,h)+problem[h].second);
    if (e>=problem[h].first)
        dp[make_tuple(h,e,dc,crashTime)]=max(dp[make_tuple(h,e,dc,crashTime)],solve(h+1,e-problem[h].first,dc,(crashTime!=-1?crashTime+1:-1))+problem[h].second);
    return dp[make_tuple(h,e,dc,crashTime)]=max(dp[make_tuple(h,e,dc,crashTime)],solve(h+1,e+sleep,dc,(crashTime!=-1?crashTime+1:-1)));
}

int main() {
    scanf("%d",&T);
    while(T--){
        dp.clear();
        scanf("%d%d%d%d%d%d",&hours,&energy,&sleep,&drinkCount,&drink,&crash);
        for (int i=0;i<hours;i++)
            scanf("%d%d",&problem[i].first,&problem[i].second);
        printf("%lld\n",solve(0,energy,drinkCount,-1));
    }
    return 0;
}
