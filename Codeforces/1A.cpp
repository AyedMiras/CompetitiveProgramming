#include <iostream>
#include <math.h>

using namespace std;

int main () {
	
	int N,M,a;
	unsigned long long int res;
	cin >> N >> M >> a;
	res = ceil((double)N/a) * ceil ((double)M/a);
	cout << res;
		
	
	return 0;
}
