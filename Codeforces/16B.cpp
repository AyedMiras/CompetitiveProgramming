#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
int n,m,s,res;
ii c[22];

bool comp(ii a, ii b) {
    return(a.second > b.second);
}

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++)
        cin >> c[i].first >> c[i].second;
    sort(c,c+m,comp);
    for (int i=0;i<m;i++) {
        if (s+c[i].first> n) {
            res+=(n-s)*c[i].second;
            break;
        }
        else res+= c[i].first*c[i].second;
        s+=c[i].first;
    }
    cout << res << endl;
}
