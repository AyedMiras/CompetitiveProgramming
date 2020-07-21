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

int main() {
    ios::sync_with_stdio(0);
    freopen("tsp.in","r",stdin);
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp >> z[i].x >> z[i].y;
    }
    for (int i=0;i<N-1;i++) {
        double minD=INF;
        int k=N-1;
        for (int j=i+1;j<N;j++) {
            if (dist(i,j)<minD)
                minD=dist(i,j),k=j;
        }
        swap(z[k],z[i+1]);
    }
    double totDist=0;
    for (int i=0;i<N;i++)
        totDist+=dist(i,(i+1)%N);
    cout << setprecision(12) << totDist << endl;
}
