#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,m,a[50],b[50];

ll _max(ll a, ll b, ll c, ll d) {
    return max(max(c,max(a,b)),d);
}

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<m;i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+m);
    ll pr = -LLONG_MAX;
    int max_i;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i]*b[j] > pr)
                pr = a[i]*b[j],max_i = i;
    pr = -LLONG_MAX;
    for (int i=0;i<n;i++) {
        if (i== max_i)
            continue;
        for (int j=0;j<m;j++)
            if (a[i]*b[j] > pr)
                pr = a[i]*b[j];
    }
    cout << pr << endl;


}
