#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int res=0;
	string input;
	for (int i=0;i<N;i++) {
		cin >> input;
		if (input[1] == '+') res++;
		else res--;
	}
	cout << res;
	
	return 0;
}
