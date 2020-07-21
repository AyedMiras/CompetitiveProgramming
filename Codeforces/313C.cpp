#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
using namespace std;
const int N = 2000200;
int n;//,grid[(int)sqrt(N)][(int)sqrt(N)];
ll a[N];

pll beauty(int i, int j, int l, int ind, int mul) {
    if (l==1) {
        //grid[i][j]=a[ind];
        return make_pair(a[ind],a[ind]);
    }
    pll s = make_pair(0,0);
    pll curr;
    curr = beauty(i,j,l/2,ind,4*mul),s.first+=curr.first,s.second = max(s.second,curr.second);
    curr = beauty(i,j+(l/2),l/2,ind+mul,4*mul),s.first+=curr.first,s.second = max(s.second,curr.second);
    curr = beauty(i+(l/2),j,l/2,ind+2*mul,4*mul),s.first+=curr.first,s.second = max(s.second,curr.second);
    curr = beauty(i+(l/2),j+(l/2),l/2,ind+3*mul,4*mul),s.first+=curr.first,s.second = max(s.second,curr.second);
    s.first+=s.second;
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n,greater<ll>());
    cout << beauty(0,0,(int)sqrt(n),0,1).first << endl;
    /*for (int i=0;i*i<n;i++) {
        for (int j=0;j*j<n;j++) {
                cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
    // 16 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
}
