#include <bits/stdc++.h>
using namespace std;
const int N=200200;
int n,h,l[N],r[N],diff[N],cum[N];

int main() {
    cin >> n >> h;
    for (int i=0;i<n;i++)
        cin >> l[i] >> r[i];
    cum[0]=r[0]-l[0];
    for (int i=1;i<n;i++)
        cum[i] = cum[i-1]+r[i]-r[i-1],diff[i]+=diff[i-1]+l[i]-r[i-1];
    int ll=0,rr=1,d=0,diff_i=0,diff_j=1;
    while(rr<n) {
        if (rr==ll)
            rr++;
        else if (diff[rr]-diff[ll]<=h) {
            if (d<cum[rr]-(ll?cum[ll]:0))
                d=cum[rr]-(ll?cum[ll]:0),diff_j=rr,diff_i=ll;
            rr++;
        }
        else
            ll++;
    }
    cout << h - (diff[diff_j] - diff[diff_i])+ d << endl;


}
