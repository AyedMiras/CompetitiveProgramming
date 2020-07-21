#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
ll n,m,a[N],s,bonus;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0;i<n;i++)
        cin >> a[i];
    if (n==1)
        return cout << 0 << endl,0;
    sort(a,a+n,greater<ll>());
    for (int i=1;i<n;i++){
        if (a[i-1]>a[i]) {
            if (bonus+a[i]<a[i-1])
                s+=bonus+a[i],bonus=0;
            else
                s+=a[i-1]-1,bonus-=a[i-1]-a[i]-1;
        }
        else {
            s+=a[i]-1;
            if (a[i]!=1)
                bonus++;
        }
    }
    if (bonus<a[n-1])
        s+=bonus;
    else
        s+=a[n-1]-1;
    cout << s << endl;
}
