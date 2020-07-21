#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,cnt,a[N];
deque<int> dq;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i], dq.push_back(a[i]);
    sort(a,a+n);
    while(cnt<n && (dq.front()!=a[0] || dq.back()!=a[n-1]))
        dq.push_front(dq.back()),dq.pop_back(),cnt++;
    cout << (cnt==n?-1:cnt) << endl;
}
