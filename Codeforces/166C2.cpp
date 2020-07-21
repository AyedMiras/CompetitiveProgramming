#include <bits/stdc++.h>
using namespace std;
const int N=505;
int n,x,a,cnt;
multiset<int> m;

int main() {
    cin >> n >> x;
    for (int i=0;i<n;i++)
        cin >> a,m.insert(a);
    multiset<int>::iterator it = m.begin();
    advance(it,(n+1)/2 -1);
    while(*it!=x) {
        m.insert(x);
        n++;cnt++;
        it = m.begin();
        advance(it,(n+1)/2 -1);
    }
    cout << cnt << endl;
}
