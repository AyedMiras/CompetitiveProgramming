#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll x[2],m,cnt;

/*
typedef struct {
    ll mat[2][2];
}Matrix;

Matrix mul(Matrix a, Matrix b ) {
    Matrix c;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            c.mat[i][j]=0;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
    return c;
}

Matrix pow(Matrix a, ll n) {
    if (!n) {
        Matrix res;
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++)
                res.mat[i][j] = (i==j);
        return res;
    }
    Matrix res = pow(a,n/2);
    if (n&1)
        return mul(mul(res,res),a);
    return mul(res,res);
}

ll fib(ll n) {
    if (!n || n==1)
        return n;
    Matrix f;
    f.mat[0][0]=f.mat[0][1]=f.mat[1][0]=1;
    f.mat[1][1]=0;
    f = pow(f,n);
    return f.mat[0][0];
}*/

int main() {
    cin >> x[0] >> x[1] >> m;
    sort(x,x+2);
    if (x[0]<=0 && x[1]<=0 && m>0)
        return 0*printf("-1\n");
    if (x[0]<0 && x[1]<0 && x[1]<m)
        return 0*printf("-1\n");
    ll f0=0, f1=1;
    while(f0*x[0] + f1*x[1] < m) {
        cnt++;
        cout << f0*x[0] + f1*x[1] << endl;
        cout << f1 << " " << f0 << endl;
        f1 = f0 + f1;
        f0 = f1 - f0;
    }
    cout << f1 << " " << f0 << " " << cnt << endl;
}

