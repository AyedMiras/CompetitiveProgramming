#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int INF=10000100;
int n,c[N];
string s;
map<string,int> vit;

void init() {
    vit["A"]=INF;
    vit["B"]=INF;
    vit["C"]=INF;
    vit["AB"]=INF;
    vit["AC"]=INF;
    vit["BC"]=INF;
    vit["ABC"]=INF;
}

int main() {
    init();
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> c[i] >> s;
        sort(s.begin(),s.end());
        vit[s]=min(vit[s],c[i]);
    }
    int res=INF;
    res = min(vit["A"]+vit["B"]+vit["C"],vit["A"]+vit["BC"]);
    res = min(res,vit["B"]+vit["AC"]);
    res = min(res,vit["C"]+vit["AB"]);
    res = min(res,vit["AB"]+vit["BC"]);
    res = min(res,vit["AB"]+vit["AC"]);
    res = min(res,vit["AC"]+vit["BC"]);
    res = min(res,vit["ABC"]);
    cout << (res==INF?-1:res) << endl;
}
