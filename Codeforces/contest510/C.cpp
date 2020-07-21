#include <bits/stdc++.h>
using namespace std;
const int N=200200;
const int INF=(int)1e9+10;
int n,a[N],z_ind,nb_z,nb_n;
bool printed[N];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i];
        if (a[i]<0)
            nb_n++;
    }
    if (nb_n&1) {
        int last=-1,flag=0,ind=-1,m4x=-INF;
        for (int i=0;i<n;i++) {
            if (a[i]<0 && a[i]>m4x)
                m4x=max(m4x,a[i]),ind=i;
        }
        cout << 2 << " " << ind+1 << endl;
        printed[ind]=1;
        for (int i=0;i<n;i++) {
            if (!printed[i] && last==-1)
                last=i;
            else if (!printed[i] && last!=-1){
                cout << 1 << " " << last+1 << " " << i+1 << endl;
                last=i;
            }
        }
    }
    else {
        int last=-1,cnt=0;
        for (int i=0;i<n;i++) {
            if (!a[i] && last==-1)
                last=i;
            else if (!a[i] && last!=-1) {
                cout << 1 << " " << last+1 << " " << i+1 << endl;
                printed[last]=1;
                last=i;
                cnt++;
            }
        }
        if (cnt==n-1)
            return 0;
        if (last!=-1) {
            cout << 2 << " " << last+1 << endl;
            printed[last]=1;
        }
        //for (int i=0;i<n;i++)
        //    cout << printed[i] << " \n"[i==n-1];
        last=-1;
        for (int i=0;i<n;i++) {
            if (!printed[i] && last==-1)
                last=i;
            else if (!printed[i] && last!=-1) {
                cout << 1 << " " << last+1 << " " << i+1 << endl;
                last=i;
            }
        }
    }
}
