#include <bits/stdc++.h>
using namespace std;
const int N=330;
const int M=330;
const int INF=0x3f3f3f3f;
int n,m,a[N],l[M],r[M];
vector<int> bPtr[N];

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++) {
        cin >> l[i] >> r[i];
        l[i]--,r[i]--;
    }
    for(int i=0;i<m;i++)
        for(int j=l[i];j<=r[i];j++)
            bPtr[j].push_back(i);
    int diff=-INF,ind;
    for(int i=0;i<n;i++) {
        for(int j=0;j<bPtr[i].size();j++)
            for(int k=l[bPtr[i][j]];k<=r[bPtr[i][j]];k++)
                a[k]--;
        int _max=-INF;
        for(int j=0;j<n;j++)
            _max=max(_max,a[j]);
        if(_max-a[i]>diff)
            diff=_max-a[i],
            ind=i;
        for(int j=0;j<bPtr[i].size();j++)
            for(int k=l[bPtr[i][j]];k<=r[bPtr[i][j]];k++)
                a[k]++;
    }
    cout << diff << endl;
    cout << bPtr[ind].size() << endl;
    for(int i=0;i<bPtr[ind].size();i++)
        cout << bPtr[ind][i]+1 << " \n"[i==bPtr[ind].size()-1];
}
