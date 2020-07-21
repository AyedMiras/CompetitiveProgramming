#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n;
pair<int,int> c[N];

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> c[i].first >> c[i].second;
    sort(c,c+n);
    for (int i=0;i<n-1;i++)
        if (c[i].first < c[i+1].first && c[i].second > c[i+1].second)
            return 0*printf("Happy Alex\n");
    cout << "Poor Alex" << endl;
}
