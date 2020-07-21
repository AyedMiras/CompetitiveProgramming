#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,cnt,a[N],b[N],ind[N];

bool comp(int i, int j) {
    return a[i]<a[j];
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i] >> b[i],ind[i]=i;
    sort(ind,ind+n,comp);
    int mB = b[ind[0]];
    for (int i=1;i<n;i++) {
        if (b[ind[i]] < mB)
            cnt++;
        mB=max(mB,b[ind[i]]);
    }
    cout << cnt << endl;
}
