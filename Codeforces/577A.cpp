#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main () {
	int n,x,cmp=0;
	cin >> n >> x;
	for (int i=1;i<= min((double)n,sqrt(x)) ;i++){
		if (!(x%i) && x/i <=n) {
			if (i!=sqrt(x)) cmp++;
			cmp++;
		}

	}
	cout << cmp << endl;

	return 0;
}
