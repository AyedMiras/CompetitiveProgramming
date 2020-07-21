#include <bits/stdc++.h>
using namespace std;
int n,cnt;
string s;

int main() {
    cin >> n >> s;
    for (int i=0;s[i];i++)
        if (s[i]=='8')
            cnt++;
    cout << min(cnt,n/11) << endl;
}
