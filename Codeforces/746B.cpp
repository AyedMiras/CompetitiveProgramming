#include <bits/stdc++.h>
using namespace std;
int n;
string s;
vector<char> decoded;

int main() {
    cin >> n >> s;
    decoded.resize(n);
    int flag = (n&1?1:-1);
    for (int i=1;i<=n;i++) {
            decoded[(n-!(n&1))/2 +flag*(i/2)] = s[i-1],flag*=-1;
    }
    for (int i=0;i<n;i++)
        cout << decoded[i];
    cout << endl;
}
