#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
int n,ind[N],parent[N];
ll st[4*N],dp[N],r,h;
pair<ll,int> v[N];

bool comp(int i,int j){
    return v[i]<v[j];
}

ll query(int si,int ss,int se,int qs,int qe) {
    if (ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return st[si];
    int mid = ss+(se-ss)/2;
    return max(query(2*si+1,ss,mid,qs,qe),query(2*si+2,mid+1,se,qs,qe));
}

void update(int si,int ss,int se,int i,ll q) {
    if (ss>i || se<i)
        return;
    if (ss==se) {
        st[si]=q;
        return;
    }
    int mid = ss+(se-ss)/2;
    update(2*si+1,ss,mid,i,q);
    update(2*si+2,mid+1,se,i,q);
    st[si]=max(st[2*si+1],st[2*si+2]);
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> r >> h;
        v[i].first=r*r*h;
        v[i].second=-i;
    }
    sort(v,v+n);
    update(0,0,n-1,-v[0].second,v[0].first);
    for (int i=1;i<n;i++) {
        dp[i]=query(0,0,n-1,0,-v[i].second)+v[i].first;
        update(0,0,n-1,-v[i].second,dp[i]);
    }
    cout << setprecision(16) << (double)(query(0,0,n-1,0,n-1))*acos(-1.L) << endl;
}
