#include <iostream>

using namespace std;

int main() {
  int N;
  unsigned long long int res=1;
  cin >> N;
  res = (res << N+1) - 2;
  cout << res;


  return 0;
}
