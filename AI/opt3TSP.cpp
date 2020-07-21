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
    i%=N,j%=N;
    return sqrt(sqr(z[i].x-z[j].x) + sqr(z[i].y-z[j].y));
}

void rev(int i, int j) {
    i%=N,j%=N;
    if (i>j)
        j+=N;
    for (int k=0;i+k<=j-k;k++)
        swap(z[(i+k)%N],z[(j-k)%N]);
}

int main() {
    ios::sync_with_stdio(0);
    freopen("tsp.in","r",stdin);
    for (int i=0;i<N;i++) {
        int temp;
        cin >> temp >> z[i].x >> z[i].y;
    }
    ///opt-3 Optimization
    bool flag=false;
    while(!flag) {
        flag=true;
        for (int i=1;i<N-4;i++) {
            for (int j=i+2;j<N-2;j++) {
                for (int k=j+2;k<N;k++) {
                    double currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    ///1 opt-2 Move
                    if (dist(i,k)+dist(i+1,k+1)+dist(j,j+1)<currD){
                        rev(k+1,i);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    if (dist(i,i+1)+dist(j,k)+dist(j+1,k+1)<currD) {
                        rev(j+1,k);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    if (dist(i,j)+dist(i+1,j+1)+dist(k,k+1)<currD) {
                        rev(i+1,j);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    ///2 opt-2 Moves
                    if (dist(i,j)+dist(i+1,k)+dist(j+1,k+1)<currD) {
                        rev(i+1,j),rev(j+1,k);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    if (dist(i,k)+dist(i+1,j+1)+dist(j,k+1)<currD) {
                        rev(i+1,j),rev(k+1,i);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    if (dist(i,j+1)+dist(i+1,k+1)+dist(j,k)<currD) {
                        rev(j+1,k),rev(k+1,i);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                    ///3 opt-2 Moves
                    if (dist(i,j+1)+dist(j,k+1)+dist(k,i+1)<currD) {
                        rev(i+1,j),rev(j+1,k),rev(k+1,i);
                        flag=0;
                        currD=dist(i,i+1)+dist(j,j+1)+dist(k,k+1);
                    }
                }
            }
        }
    }
    double totDist=0;
    for (int i=0;i<N;i++)
        totDist+=dist(i,(i+1)%N);
    cout << setprecision(12) << totDist << endl;
}

