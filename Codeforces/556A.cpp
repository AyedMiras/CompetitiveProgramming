#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool flag;
string s;

int main() {
    cin >> n >> s;
    cnt = s.length();
    for (int i=0;i+1<s.length();) {
        if (s[i]!=s[i+1]) {
            cnt-=2;
            if (i) --i,s.erase(i+1,2);
            else s.erase(i,2);
        }
        else
            i++;
    }
    cout << cnt << endl;
}
