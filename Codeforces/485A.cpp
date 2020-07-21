#include <bits/stdc++.h>
using namespace std;
long long int a,m;
bool _mod[100010];
int main() {
    ios::sync_with_stdio(0);
    cin >> a >> m;
    while(a%m && !_mod[a%m])
        _mod[a%m]=true,a+= a%m;
    if (a%m)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
