#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int N = 500500;
int n,a[N];
lli cum[N];
pair<lli,int> cump[N];

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n<3) return 0*printf("0\n");
    for (int i=1;i<=n;i++) {
        cum[i]=a[i]+cum[i-1];
        cump[i].first=a[i]+cump[i-1].first;
        cump[i].second = i;
    }
    sort(cump+1,cump+n+1);
    //for (int i=1;i<=n;i++) cout << cump[i].first << " \n"[i==n];
    lli cnt=0;
    for (int i=2;i<=n-1;i++) {
        if (cum[i]%2 == 0 && cum[i]/2 == cum[n]-cum[i]) {
            //cout << i << " ";
            pair<lli, int> key;key.first=cum[i]/2;key.second=i-1;
            pair<lli, int> key2;key2.first=cum[i]/2;key2.second=0;
            int l = lower_bound(cump+1,cump+n+1,key2) - cump;
            int r = upper_bound(cump+1,cump+n+1,key) - cump;
            //cout << l << " " << r << endl;
            if (cump[l].first != cum[i]/2) continue;
            cnt+= r-l;
        }
    }
    cout << cnt << endl;
}
