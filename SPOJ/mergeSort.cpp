#include <bits/stdc++.h>
using namespace std;
int a[6] = {12, 11, 13, 5, 6, 7};

void fusion(int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;

    int L[6];
    int R[6];
    for (int i=0;i<n1;i++) L[i] = a[l+i];
    for (int i=0;i<n2;i++) R[i] = a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j <n2) {
        if (L[i] >= R[j]) {
            a[k++]=R[j++];
        }
        else {
            a[k++]=L[i++];
        }
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}
void mergeSort(int l, int r) {
    if (l>=r) return ;
    int mid = l + (r-l)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    fusion(l,mid,r);
}
int main() {
    for (int i=0;i<6;i++) cout << a[i] << " ";
    mergeSort(0,5);
    for (int i=0;i<6;i++) cout << a[i] << " ";
}
