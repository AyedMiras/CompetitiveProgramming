#include <bits/stdc++.h>
using namespace std;
int n,t;
string s;

int main() {
    cin >> n >> t >> s;
    while(t--) {
        for (int i=0;i<n-1;i++) {
            if (s[i] == 'B' && s[i+1] == 'G') swap(s[i],s[i+1]),i++;
        }
    }
    for (int i=0;s[i];i++) cout << s[i];
    cout << endl;
}
