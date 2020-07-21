#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N=100100;
int n,l[N],r[N];
ll res;

int main(){
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> l[i] >> r[i];
    sort(l,l+n);
    sort(r,r+n);
    for (int i=0;i<n;i++)
        res+=max(l[i],r[i]);
    cout << res+n << endl;
}
