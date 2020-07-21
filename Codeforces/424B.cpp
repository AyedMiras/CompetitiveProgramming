#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,s,x[N],y[N],k[N],ind[N];
long long int cum[N];

double dist(int x, int y) {
    return sqrt(x*x + y*y);
}

bool comp(int i, int j) {
    return dist(x[i],y[i]) < dist(x[j],y[j]);
}

int main() {
    setprecision(7);
    cin >> n >> s;
    for (int i=1;i<=n;i++)
        cin >> x[i] >> y[i] >> k[i],ind[i]=i;
    sort(ind+1,ind+n+1,comp);
    cum[0]=s;
    for (int i=1;i<=n;i++)
        cum[i] = k[ind[i]] + cum[i-1];
    int lb = lower_bound(cum+1,cum+n+1,1000000) - cum;
    cout << fixed << (lb==n+1?-1:dist(x[ind[lb]],y[ind[lb]])) << endl;

}
