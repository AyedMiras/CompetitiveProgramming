#include <bits/stdc++.h>
using namespace std;
string s;
int m,sum,k,w[27];

int main() {
    cin >> s >> k;
    for(int i=0;i<26;i++) cin >> w[i],m = max(m,w[i]);
    for (int i=0;i<s.length()+k;i++) {
            if (i<s.length()) sum+= w[s[i]-'a']*(i+1);
            else sum+=m*(i+1);
    }
    cout << sum << endl;
}
