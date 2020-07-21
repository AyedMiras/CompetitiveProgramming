#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,L,a,cnt;
pair<int,int> t[N];

int main() {
    cin >> n >> L >> a;
    for (int i=0;i<n;i++)
        cin >> t[i].first >> t[i].second;
    sort(t,t+n);
    if (!n)
        return 0*printf("%d",L/a);
    for (int i=0;i<n-1;i++) {
        cnt+=(t[i+1].first - t[i].first - t[i].second)/a;
    }
    cnt+=(t[0].first)/a;
    cnt+=(L-t[n-1].first-t[n-1].second)/a;
    cout << cnt << endl;

}
