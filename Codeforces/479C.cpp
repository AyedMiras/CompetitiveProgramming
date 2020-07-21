#include <bits/stdc++.h>
#define ii pair<int,int>
using namespace std;
const int N = 5005;
int n;
ii c[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> c[i].first >> c[i].second;
    if (n==1) return 0*printf("%d\n",c[0].second);
    sort(c,c+n);
    //for (int i=0;i<n;i++) cout << c[i].first << " " << c[i].second << endl;
    int prevday = 0;
    for (int i=0;i<n;i++) {
        if (prevday <= c[i].second) prevday = c[i].second;
        else prevday = c[i].first;
    }
    cout << prevday << endl;
}
