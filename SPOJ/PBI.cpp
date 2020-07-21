#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n,T,a[N],l[N],r[N],ind[N],bck[N];

bool comp(int i,int j) {
        return a[i] < a[j];
}

int build(int ll, int rr) {
    if (ll>rr) return n;
    int mid = ll + (rr-ll)/2;
    l[mid]=build(ll,mid-1);
    r[mid]=build(mid+1,rr);
    return mid;
}

int main() {
    cin >> T;
    for (int t=0;t<T;t++) {
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i],ind[i]=i;
        sort(ind,ind+n,comp);
        for (int i=0;i<n;i++) bck[ind[i]] = i;
        ind[n]=-1;
        build(0,n-1);
        cout << "Case " << t+1 << ":" << endl;
        for (int i=0;i<n;i++) {
            cout << ind[l[bck[i]]]+1 << " " << ind[r[bck[i]]]+1<< endl;
        }
    }
}
