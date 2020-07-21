#include <cstdio>
#include <algorithm>
using namespace std;

int n,x;
long long int cnt;
int a[100010];
int _xor;

int main() {
    scanf("%d %d",&n,&x);
    for (int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for (int i=0;i<n;i++) {
        _xor = x^a[i];
        if (binary_search(a+i+1,a+n,_xor))
            cnt+=upper_bound(a+i+1,a+n,_xor)-lower_bound(a+i+1,a+n,_xor);
    }
    printf("%I64d\n",cnt);
}
