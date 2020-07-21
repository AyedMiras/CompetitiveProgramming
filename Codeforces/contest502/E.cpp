#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=300300;
ll n,res,a[N];
pair<ll,ll> st[4*N];

int bits(ll x) {
    int cnt=0;
    while(x) {
        if (x&1)
            cnt++;
        x/=2;
    }
    return cnt;
}

void build(int si,int ss,int se) {
    if (ss==se){
        st[si]=make_pair(bits(a[ss]),bits(a[ss]);
        return;
    }
    int mid=ss+(se-ss)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si]=make_pair(min(abs(st[2*si+1].first-st[2*si+2].second),abs()));
}

void print(int si,int ss,int se){
    cout << si << " " << ss << " " << se << ":" << endl;
    cout << st[si].first << " " << st[si].second << endl;
    if (ss!=se) {
        int mid=ss+(se-ss)/2;
        print(2*si+1,ss,mid),print(2*si+2,mid+1,se);
    }
}
ll query(int si,int ss,int se,int qs,int qe) {
    if (ss>qe || se<qs)
        return 0;
    if (ss>=qs && se<=qe)
        return st[si].second;
    int mid = ss+(se-ss)/2;
    ll q1=query(2*si+1,ss,mid,qs,qe);
    ll q2=query(2*si+2,mid+1,se,qs,qe);
    return q1+q2+q1*q2;
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    print(0,0,n-1);
    for (int i=0;i<n;i++)
        res+=query(0,0,n-1,i,n-1);
    cout << res << endl;
}
