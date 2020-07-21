#include <iostream>

using namespace std;

int main () {
	int N;
	cin >> N;
	for (int i=0;i< N;i++) {
		string input;
		cin >> input;
		int len = input.length();
		if (len >10) cout << input[0]<< len-2 <<input[len-1] <<endl;
		else cout << input << endl;
	}
	
	return 0;
}
