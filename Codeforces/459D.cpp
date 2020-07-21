#include <bits/stdc++.h>
using namespace std;
const int N=1001000;
int n,a[N],f1[N],f2[N];
long long int cnt;
map<int,int> occ;

void _merge(int l,int r){
    int mid =l+(r-l)/2;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int f11[n1],f12[n2],f21[n1],f22[n2];
    for (int i=0;i<n1;i++)
        f11[i]=f1[l+i],f21[i]=f2[l+i];
    for (int i=0;i<n2;i++)
        f12[i]=f1[mid+1+i],f22[i]=f2[mid+1+i];
    int i=0,j=0;
    while(i<n1 && j<n2) {
        if (f11[i]>f22[j])
            j++,cnt+=n1-i;
        else
            i++;
    }
    i=0,j=0;
    while(i<n1 && j<n2)
        f1[l+i+j]=(f11[i]>f12[j]?f12[j++]:f11[i++]);
    while(i<n1)
        f1[l+i+j]=f11[i++];
    while(j<n2)
        f1[l+i+j]=f12[j++];
    i=0,j=0;
    while(i<n1 && j<n2)
        f2[l+i+j]=(f21[i]>f22[j]?f22[j++]:f21[i++]);
    while(i<n1)
        f2[l+i+j]=f21[i++];
    while(j<n2)
        f2[l+i+j]=f22[j++];
}

void mergeSort(int l, int r) {
    if (l>=r)
        return;
    int mid = l+(r-l)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    _merge(l,r);
}

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    for (int i=0;i<n;i++)
        occ[a[i]]++,f1[i]=occ[a[i]];
    occ.clear();
    for (int i=n-1;i>=0;i--)
        occ[a[i]]++,f2[i]=occ[a[i]];
    mergeSort(0,n-1);
    cout << cnt << endl;
}
