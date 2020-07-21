#include <bits/stdc++.h>
using namespace std;
int n,m;
map<string,int> mm;
vector<string> a,b;

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        string w1,w2;
        cin >> w1 >> w2;
        a.push_back(w1);
        b.push_back(w2);
        mm[w1]=i;
    }
    for (int i=0;i<n;i++) {
        string w;
        cin >> w;
        int ind = mm[w];
        cout << (a[ind].length()<=b[ind].length()?a[ind]:b[ind]) << " \n"[i==n-1];
    }
}
