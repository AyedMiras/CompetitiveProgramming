#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N=(ll)1e9+7;
ll n,m,xc,yc,k,dx,dy,cnt;

bool isValid(ll i,ll j) {
    return i>=0 && j>=0 && i<n && j<m;
}

int main() {
    cin >> n >> m >> xc >> yc >> k;
    xc--,yc--;
    for (int i=0;i<k;i++) {
        cin >> dx >> dy;
        ll l=0,r=N,steps=0;
        while(l<r) {
            int mid = l + (r-l)/2;
            isValid(xc+mid*dx,yc+mid*dy)?l=mid+1,steps=mid:r=mid;
        }
        cnt+=steps;
        xc+=steps*dx;
        yc+=steps*dy;
    }
    cout << cnt << endl;
}
