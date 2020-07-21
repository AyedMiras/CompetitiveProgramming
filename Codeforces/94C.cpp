#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt;

int main() {
    cin >> n >> m >> a >> b;
    int r = n/m + (n%m?1:0);
    a--,b--;
    if (b/m == a/m)
        cnt++;
    else if (b/m == a/m +1) {
        if (a%r==0 && (b%r==r-1 || b==r-1))
            cnt=1;
        else
            cnt=2;
    }
    else {
        if (a%r==0 && (b%r==r-1 || b==r-1))
            cnt=1;
        else if (a%r==0 || b%r==r-1 || b==r-1)
            cnt=2;
        else if (b%r+1==a%r)
            cnt=2;
        else
            cnt=3;
    }
    cout << cnt << endl;
}
