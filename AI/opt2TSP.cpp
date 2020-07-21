#include <bits/stdc++.h>
using namespace std;
const int N=194;
const int INF=0x3f3f3f3f;
typedef struct {
    double x,y;
} point;

point z[N];

double sqr(double x) {
    return x*x;
}

double dist(int i, int j) {
    return sqrt(sqr(z[i].x-z[j].x) + sqr(z[i].y-z[j].y));
}

void rev(int i, int j) {
    for (int k=0;i+k<=j-k;k++)
        swap(z[i+k],z[j-k]);
}

int main() {
    ios::sync_with_stdio(0);
    freopen("tsp.in","r",stdin);
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp >> z[i].x >> z[i].y;
    }
    ///Opt2
    bool flag=false;
    int cnt=0;
    while(!flag) {
        flag=true;
        for (int i=0;i<N-2;i++) {
            for (int j=i+2;j<N;j++) {
                if (dist(i,j)+dist(i+1,j+1) < dist(i,i+1) + dist(j,j+1))
                    rev(i+1,j),flag=false;
            }
        }
    }
    double totDist=0;
    for (int i=0;i<N;i++)
        totDist+=dist(i,(i+1)%N);
    cout << setprecision(12) << totDist << endl;
}
