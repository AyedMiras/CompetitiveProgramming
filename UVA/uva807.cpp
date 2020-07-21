#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
const int N=100100;

struct pt {
    int x,y;
};

struct line {
    double a,b,c;
};

int T,n;
long long int cnt;
pair<pt,pt> seg[N];
line l[N];

double det(double a, double b, double c, double d) {
    return a*d-b*c;
}

bool intersect(line m, line n, pt* res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (fabs(zn) < eps)
        return false;
    res->x = -det(m.c, m.b, n.c, n.b) / zn;
    res->y = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool inSegment(pt a, pt b, pt p) {
    return (p.x >= min(a.x,b.x) && p.x<=max(a.x,b.x) && p.y<=max(a.y,b.y) && p.y>=min(a.y,b.y));
}

line pointToLine(pt p1, pt p2) {
    line l;
    if (p1.x==p2.x) {
        l.a=1.0,l.b=0.0,l.c=-p1.x;
    }
    else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        cnt=n;
        for (int i=0;i<n;i++) {
            cin >> seg[i].first.x >> seg[i].first.y >> seg[i].second.x >> seg[i].second.y;
            l[i] = pointToLine(seg[i].first,seg[i].second);
        }
        for (int i=0;i<n;i++) {
            for (int j=i+1;j<n;j++) {
                pt p;
                if (intersect(l[i],l[j],&p) && inSegment(seg[i].first,seg[i].second,p) && inSegment(seg[j].first,seg[j].second,p))
                    cnt+=2;
            }
        }
        cout << cnt << endl;
    }
}
