#include <iostream>

using namespace std;

int main() {
  int N,parity,input[105];
  cin >> N;
  cin >> input[0];
  cin >> input[1];
  cin >> input[2];
  if ( (input[0]&1)+ (input[1]&1) + (input[2]&1) > 1)
    parity = 1;
  else
    parity = 0;
  for (int i=3;i<N;i++) cin >> input[i];
  for (int i=0;i<N;i++)
    if ((input[i]&1) != parity){
      cout << i+1 << endl;
      break;
    }
  return 0;
}
