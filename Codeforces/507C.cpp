#include <bits/stdc++.h>
using namespace std;
long long int h,n,cnt;
stack<int> path;

int main() {
    cin >> h >> n;
    n+= (1LL<<h)-1;
    while(n!=1)
        path.push(n&1),n/=2;
    int prev=-1;
    while (!path.empty()) {
        if (prev==-1 && path.top()==1)
            cnt+=(1LL<<h)-1;
        else if (prev == path.top())
            cnt+=(1LL<<h)-1;
        cnt++,h--;
        prev=path.top();
        path.pop();
    }
    cout << cnt << endl;
}
