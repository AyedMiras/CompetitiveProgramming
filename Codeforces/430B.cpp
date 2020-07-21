#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,k,x,res,a[N];
vector<int> l,r;

int main() {
    cin >> n >> k >> x;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int curr=0;
    for(int i=1;i<n;i++) {
        if(a[i]!=a[i-1]) {
            l.push_back(curr);
            r.push_back(i-1);
            curr=i;
        }
    }
    l.push_back(curr),r.push_back(n-1);
    for(int i=0;i<l.size();i++) {
        if(a[l[i]]==x && r[i]-l[i]+1>=2) {
            int j1=i-1,j2=i+1,cnt=r[i]-l[i]+1;
            while(j1>=0 && j2<l.size() && a[l[j1]]==a[l[j2]] && r[j1]-l[j1]+r[j2]-l[j2]+2>=3) {
                cnt+=r[j1]-l[j1]+r[j2]-l[j2]+2;
                j1--,j2++;
            }
            res=max(res,cnt);
        }
    }
    cout << res << endl;
}
