#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 200200;
int T,n,a[N];

ll _merge(int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int i=0,j=0,k=l;
    ll inv=0;
    int L[N],R[N];
    for (int i=0;i<n1;i++) L[i]=a[l+i];
    for (int i=0;i<n2;i++) R[i]=a[m+1+i];

    while(i<n1 && j<n2) {
        if (L[i] > R[j])
            a[k++] = R[j++],inv+=n1-i;
        else
            a[k++] = L[i++];
    }
    while(i<n1)
        a[k++] = L[i++];
    while(j<n2)
        a[k++] = R[j++];
    return inv;
}
ll mergeSort(int l, int r) {
    if (l>=r) return 0;
    int mid = l+ (r-l)/2;
    ll inv = mergeSort(l,mid);
    inv+=mergeSort(mid+1,r);
    inv+=_merge(l,mid,r);
    return inv;
}

int main(){
    cin >> T;
    while(T--) {
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        cout << mergeSort(0,n-1) << endl;
    }
}
