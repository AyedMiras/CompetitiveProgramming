#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int H=200;
ll T,hours,energy,sleep,drinkCount,drink,crash;
pair<ll,ll> problem[H];
map<tuple<int,int,int,int>,int> dp;

ll solve(int h,ll e,int dc,int crashTime) {
    if (e<0 || dc<0 || h==hours)
        return 0;
    if (dp.find(make_tuple(h,e,dc,crashTime))!=dp.end())
        return dp[make_tuple(h,e,dc,crashTime)];
    if (crashTime==h-2)
        return dp[make_tuple(h,e,dc,crashTime)]=solve(h,e,dc,-1);
    return dp[make_tuple(h,e,dc,crashTime)]=max(max(solve(h+1,e+sleep,dc,(crashTime!=-1?crashTime+1:-1)),solve(h+1,energy+drink,dc-1,h)),solve(h+1,e-problem[h].first,dc,(crashTime!=-1?crashTime+1:-1)) + problem[h].second);
}

int main() {
    cin >> T;
    while(T--){
        cin >> hours >> energy >> sleep >> drinkCount >> drink >> crash;
        for (int i=0;i<hours;i++)
            cin >> problem[i].first >> problem[i].second;
        cout << solve(0,energy,drinkCount,-1) << endl;
    }
    return 0;
}
