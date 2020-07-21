#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,ax,ay,bx,by,cx,cy;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    if ( (ax<bx && ax>cx) || (ax<cx && ax>bx))
        return cout << "NO" << endl,0;
    if ( (ay<by && ay>cy) || (ay<cy && ay>by))
        return cout << "NO" << endl,0;
    cout << "YES" << endl;
}
