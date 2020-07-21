#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
using namespace std;
const int N=550;
const ll MOD=998244353;
int n;
ll a[N],res=1LL;
map<ll,ll> cff;
set<ll> s;

ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}

ll isPow(ll x,ll p){
    ull l=0,r=(p==2?2e9:(p==3?2e6:1e5));
    while(l<=r){
        ull mid = l+(r-l)/2;
        ull pow = 1;
        for (int i=0;i<p;i++)
            pow*=mid;
        if (pow==x)
            return mid;
        if (pow<x)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}

int main(){
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++){
        ll p = isPow(a[i],4);
        if (p!=-1) {
            cff[p]+=4;
            continue;
        }
        p = isPow(a[i],3);
        if (p!=-1) {
            cff[p]+=3;
            continue;
        }
        p = isPow(a[i],2);
        if (p!=-1) {
            cff[p]+=2;
            continue;
        }
        s.insert(a[i]);
    }
    for (set<ll>::iterator it=s.begin();it!=s.end();++it) {
        ll g,cnt=0;
        bool flag=0;
        for (int j=0;j<n;j++) {
            if (*it==a[j])
                cnt++;
            else if (gcd(*it,a[j])!=1)
                flag=1,g=gcd(*it,a[j]);
        }
        if (flag)
            cff[*it/g]+=cnt,cff[g]+=cnt;
        else
            res*=(1+cnt)*(1+cnt),res%=MOD;
    }
    for (map<ll,ll>::iterator it=cff.begin();it!=cff.end();++it)
        res*=(it->second+1),res%=MOD;
    cout << res << endl;
    cout.flush();
}
