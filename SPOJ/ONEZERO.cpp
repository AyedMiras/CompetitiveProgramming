#include <bits/stdc++.h>
using namespace std;
int k,n;
set<int> rem;

string bfs(int x){
    queue<pair<string,int> > q;
    rem.insert(1);
    q.push(make_pair("1",1));
    while(1) {
        string mul = q.front().first;
        int mod = q.front().second;
        if (!mod)
            return mul;
        q.pop();
        if (rem.find((mod*10)%x)==rem.end())
            q.push(make_pair(mul+"0",(mod*10)%x)),rem.insert((mod*10)%x);
        if (rem.find((mod*10+1)%x)==rem.end())
            q.push(make_pair(mul+"1",(mod*10+1)%x)),rem.insert((mod*10+1)%x);

    }
}

int main() {
    cin >> k;
    while(k--) {
        rem.clear();
        cin >> n;
        cout << bfs(n) << endl;
    }
}
