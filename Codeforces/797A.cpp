#include <cstdio>
#include <vector>
using namespace std;

int n,k;
vector <int> div;

void _div(int n) {
    int i=2;
    while (n>=i) {
        while (!(n%i))
            n=n/i,div.push_back(i);
        i++;
    }
}


int main () {
    scanf("%d %d",&n,&k);
    _div(n);
    if (div.size() <k)
        printf("-1");
    else {
        int p =1;
        for (int i=0;i<k-1;i++)
            p*= div[i],printf("%d ",div[i]);
        printf("%d\n",n/p);
    }

}
