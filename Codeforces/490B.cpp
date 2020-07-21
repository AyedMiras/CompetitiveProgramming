#include <bits/stdc++.h>
using namespace std;
int n,a,b;
map<int,int> m1,m2;
vector<int> q;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        if (!b) b = -1;
        m1[a]=b,m2[b]=a;
    }
    int ind=0;
    while(m1.find(ind)!=m1.end()) {
        //cout << ind << endl;
        q.push_back(0);
        q.push_back(m1[ind]);
        ind = m1[ind];
    }
    int l = q.size();
    l-=2;
    ind = -1;
    while(m2.find(ind)!=m2.end()) {
        q[l]=m2[ind];
        ind = m2[ind];
        l-=2;
    }
    for (int i=0;i<q.size();i++)
        cout << q[i] << " \n"[i==l-1];
}
