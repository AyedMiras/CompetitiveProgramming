#include <bits/stdc++.h>
using namespace std;
const int N=200200;
int n,l[N],r[N],ind[N];

bool comp(int i,int j) {
    return l[i]<l[j];
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> l[i] >> r[i],ind[i]=i;
    if (n<=2)
        return 0*printf("YES\n");
    sort(ind,ind+n,comp);
    int i1=0,i2=1;
    for (int i=2;i<n;i++) {
        if (l[ind[i]]>r[ind[i1]] && l[ind[i]]>r[ind[i2]]) {
            if (i1<i2)
                i1=i;
            else
                i2=i;
        }
        else if (l[ind[i]]>r[ind[i1]])
            i1=i;
        else if (l[ind[i]]>r[ind[i2]])
            i2=i;
        else
            return 0*printf("NO\n");
    }
    cout << "YES" << endl;
}
