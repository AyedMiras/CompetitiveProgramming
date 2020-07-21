#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main () {
	
	int N;
	cin >> N;
	for (int j=0;j< N ; j++)
	{
		string input;
		cin >> input;
		int l = input.length();
		int cnt=0,beg=0;
		int int_arg[2];
		string string_arg[2];
		for (int i=1;i<l;i++){
			
			if ( (!cnt || cnt ==2 ) && input[i] - '0' <= 9 && input[i] -'0' >=0 ) {
				string_arg[cnt/2] = input.substr(beg,i-1-beg);
				beg = i;
				cnt++;
			}
			else if ((cnt ==1) && input[i] - 'a' <= 26 && input[i] - 'a' >=0 ){	
				int_arg[0] = atoi(input.substr(beg,i-1-beg).c_str());
				beg = i;
				cnt++;
			}
				
			if (cnt==3){
				int_arg[1] = atoi(input.substr(beg,l-2-beg).c_str());
				break;
			}
		}
		cout << int_arg[0] << int_arg[1] << string_arg[0] << string_arg[1] << endl;
		if (cnt<2){
			cout << "R" << int_arg[0];
			int l = string_arg[0].length();
			int res = 0,mul = 1;
			for (int i=l-1;i>-1;i--) {
				res += (string_arg[0][i] - 'a')*mul;
				mul*=26;
			}
			cout<< "C" <<res << endl;
		}
		else {
			if (!int_arg[1]) cout << 'A';
			else
				while (int_arg[1]) {
					cout << 'a' + int_arg[1]/26;
					int_arg[1] /= 26;
				}
			cout << int_arg[0] << endl;
		}
	
		
			
	}

		
	
	return 0;
}
