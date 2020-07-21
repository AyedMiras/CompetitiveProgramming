#include <bits/stdc++.h>
using namespace std;
map<int,int> occ;
set<int> alpha;
int int_cnt =0;
string s;

int main() {
    cin >> s;
    if (s.length()<26) return 0*printf("%d\n",-1);
    int l=0,r=0;
    while (s[l]) {
        while(r<l+26 && s[r]) {
            if (s[r] == '?') int_cnt++;
            else alpha.insert(s[r]-'A');
        }
        if (s.size() + int_cnt >=26)
    }


}
