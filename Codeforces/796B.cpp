#include <bits/stdc++.h>
using namespace std;
const int N=1000100;
int n,m,k,h,pos,cup[2];
bool holed,hole[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=0;i<m;i++) cin >> h,hole[--h]=1;
    if (hole[0]) holed=true;
    for (int i=0;i<k;i++) {
        cin >> cup[0] >> cup[1];
        if (holed) continue;
        --cup[0],--cup[1];
        for (int j=0;j<2;j++) {
            if (pos==cup[j]) {
                pos = cup[1-j];
                if (hole[cup[1-j]]) holed=true;
                break;
            }
        }
    }
    cout << pos+1 << endl;
}
