#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,nices,cmp,cnt[N],s[N];
bool flag;

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> s[i],cnt[s[i]]++;
    for (int i=0;i<N;i++) {
        if (cnt[i]==1)
            nices++;
        if (cnt[i]>2)
            flag=1;
    }
    if (nices&1) {
        if (!flag)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cmp=0,flag=0;
            for (int i=0;i<n;i++) {
                if (!flag && cnt[s[i]]>2)
                    cout << "A",flag=1;
                else if (cnt[s[i]]==1 && cmp<nices/2)
                    cmp++,cout << "A";
                else
                    cout << "B";
            }
            cout << endl;
        }
    }
    else {
        cout << "YES" << endl;
        cmp=0;
        for (int i=0;i<n;i++) {
            if (cnt[s[i]]==1 && cmp<nices/2)
                cmp++,cout << "A";
            else
                cout << "B";
        }
        cout << endl;
    }
}
