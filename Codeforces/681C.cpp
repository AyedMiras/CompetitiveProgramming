#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
priority_queue<int,vector<int>,greater<int>> pq;
vector<pair<string,int> > seq;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    while(n--) {
        string s;
        int x;
        cin >> s;
        if (s!="removeMin")
            cin >> x;
        if (s=="insert")
            pq.push(x),seq.push_back(make_pair(s,x));
        if (s=="removeMin"){
            if (pq.empty()) {
                seq.push_back(make_pair("insert",0));
                pq.push(0);
            }
            seq.push_back(make_pair("removeMin",INF));
            pq.pop();
        }
        if (s=="getMin") {
            while(!pq.empty() && pq.top()< x) {
                seq.push_back(make_pair("removeMin",INF));
                pq.pop();
            }
            if (pq.empty()) {
                seq.push_back(make_pair("insert",x));
                seq.push_back(make_pair("getMin",x));
                pq.push(x);
            }
            else if (pq.top()==x)
                seq.push_back(make_pair("getMin",x));
            else if (pq.top()>x) {
                seq.push_back(make_pair("insert",x));
                seq.push_back(make_pair("getMin",x));
                pq.push(x);
            }
        }
    }
    cout << seq.size() << endl;
    for (int i=0;i<seq.size();i++) {
        cout << seq[i].first;
        if (seq[i].second != INF)
            cout << " " << seq[i].second;
        cout << endl;
    }
}
