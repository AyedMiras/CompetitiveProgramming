#include <iostream>
#include <algorithm>
#define INF 1e9

using namespace std;

int main() {
	
	int n,m,input[55];
	cin >> n >> m;
	for (int i=0;i< m; i++) cin >> input[i];
	sort(input , input+m);
	int min_v = INF;
	for (int i=0;i<m-n+1;i++)
		min_v = min(min_v, input[i+n-1] - input[i]);
	cout << min_v << endl;
	
	return 0;
}
