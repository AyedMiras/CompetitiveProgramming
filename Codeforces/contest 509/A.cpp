#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,cnt,curr,a[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    curr=a[0];
    for (int i=1;i<n;i++) {
        cnt+=a[i]-curr-1;
        curr=a[i];
    }
    cout << cnt << endl;
}
