#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,l,ind,cnt,root[N];
vector<int> lang[N];

int _find(int x) {
    return (root[x]==x)?x:root[x]=_find(root[x]);
}

void _union(int x, int y) {
    root[_find(x)]=_find(y);
}

void _init() {
    for (int i=0;i<n;i++)
        root[i]=i;
}

int main() {
    cin >> n >> m;
    _init();
    for (int i=0;i<n;i++) {
        cin >> l;
        for (int j=0;j<l;j++) {
            cin >> ind;
            lang[ind-1].push_back(i);
        }
        if (!l)
            cnt++;
    }
    for (int i=0;i<m;i++) {
        if (lang[i].size()>1) {
            for (int j=0;j<lang[i].size()-1;j++)
                _union(lang[i][j],lang[i][j+1]);
        }
    }
    if (cnt == n)
        return 0*printf("%d\n",n);
    cnt=0;
    for (int i=0;i<n;i++)
        if (_find(i)==i)
            cnt++;
    cout << cnt-1 << endl;
}
