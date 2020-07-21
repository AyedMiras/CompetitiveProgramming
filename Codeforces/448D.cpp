#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,m,k;

int main(){
    cin >> n >> m >> k;
    ll l=1,r=n*m;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll res=0,res2=0;
        for (int i=1;i<=m;i++){
            res+=min((mid-1)/i,n);
            res2+=min(mid/i,n);
        }
        if (res!=res2 && res<k && k<=res2)
            return cout << mid << endl, 0;
        if (res2<k)
            l=mid+1;
        else if (k<=res2)
            r=mid-1;
    }
}
