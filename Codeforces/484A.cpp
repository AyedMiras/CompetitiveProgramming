#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n;
ll r,l;

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> l >> r;
        int mask = 0;
        while(1) {
            if ((l|(1LL<<mask)) > r)
                break;
            l |=(1LL<<mask++);
        }
        cout << l << endl;
    }
}
