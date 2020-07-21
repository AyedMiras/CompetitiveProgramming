#include <bits/stdc++.h>
using namespace std;
const int CITIES=194;
const int ANTS=194;
const int ITERATIONS=128;
const double ALPHA=20;
const double BETA=6;
const double RHO=0.1;
const double INIT_PHERO=0.1;
const double Q=1.0;
const int INF=0x3f3f3f3f;
typedef struct {
    double x,y;
} point;

point z[CITIES];
double delta[CITIES][CITIES],tau[CITIES][CITIES],cost[ANTS],d[CITIES][CITIES];

double sqr(double x) {
    return x*x;
}

double dist(int i, int j) {
    i%=CITIES,j%=CITIES;
    return sqrt(sqr(z[i].x-z[j].x) + sqr(z[i].y-z[j].y));
}

void init() {
    double moyD=0,sigma=0;
    for(int i=0;i<CITIES;i++) {
        for(int j=i+1;j<CITIES;j++) {
            d[i][j]=d[j][i]=dist(i,j);
            moyD+=d[i][j]+d[j][i];
        }
    }
    moyD/=(CITIES*(CITIES-1));
    for(int i=0;i<CITIES;i++)
        for(int j=i+1;j<CITIES;j++)
            sigma=sqr(d[i][j]-moyD)+sqr(d[j][i]-moyD);
    sigma/=(CITIES*(CITIES-1)-1);
    cout << sigma << endl;
    for(int i=0;i<CITIES;i++)
        for(int j=i+1;j<CITIES;j++)
            d[i][j]=d[j][i]=(d[i][j]-moyD)/sigma;
    for (int c1=0;c1<CITIES;c1++)
        for (int c2=0;c2<CITIES;c2++)
            tau[c1][c2]=INIT_PHERO;
}

int main() {
    ios::sync_with_stdio(0);
    freopen("tsp.in","r",stdin);
    for (int i=0;i<CITIES;i++) {
        int temp;
        cin >> temp >> z[i].x >> z[i].y;
    }
    init();
    for (int i=0;i<ITERATIONS;i++) {
        for (int c1=0;c1<CITIES;c1++)
            for (int c2=0;c2<CITIES;c2++)
                delta[c1][c2]=0;
        for (int a=0;a<ANTS;a++) {
            vector<int> tour;
            set<int> _cities;
            tour.push_back(0);
            for (int j=1;j<CITIES;j++)
                _cities.insert(j);
            while(!_cities.empty()) {
                double sum = 0;
                vector<pair<double,int>> prob;
                int currCity=tour[tour.size()-1];
                for (set<int>::iterator it = _cities.begin();it!=_cities.end();++it) {
                    sum+=pow(tau[currCity][*it],ALPHA)*pow(1.0/d[currCity][*it],BETA);
                    prob.push_back(make_pair(pow(tau[currCity][*it],ALPHA)*pow(1.0/d[currCity][*it],BETA),*it));
                }
                sort(prob.begin(),prob.end(),greater<pair<double,int>>());
                double roulette=(double)rand()/RAND_MAX;
                double p=0;
                for (int j=0;j<prob.size();j++) {
                    p+=prob[j].first/sum;
                    if (p>=roulette) {
                        tour.push_back(prob[j].second);
                        _cities.erase(_cities.find(prob[j].second));
                        break;
                    }
                }
            }
            cost[a]=0;
            for (int j=0;j<tour.size();j++)
                cost[a]+=dist(tour[j],tour[(j+1)%CITIES]);
            for (int j=0;j<tour.size();j++)
                delta[tour[j]][tour[(j+1)%CITIES]]+=Q/cost[a];
            cout << cost[a] << endl;
        }
        for (int c1=0;c1<CITIES-1;c1++)
            for (int c2=c1+1;c2<CITIES;c2++)
                tau[c1][c2]=tau[c2][c1]=tau[c1][c2]*(1-RHO)+delta[c1][c2];
    }
    double res=(double)INF;
    for (int a=0;a<ANTS;a++)
        res=min(res,cost[a]);
    cout << setprecision(12) << res << endl;
}
