#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n,a,b,x;

int main() {
    cin >> n >> a >> b;
    for (int i=0;i<n;i++) {
        cin >> x;
        ll l=0,r=x+1;
        while(l<r) {
            ll mid = l+(r-l)/2;
            (mid*a)/b==(x*a)/b?r=mid:l=mid+1;
        }
        cout << x-l << " \n"[i==n-1];
    }
}
