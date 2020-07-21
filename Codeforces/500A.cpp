#include <iostream>

using namespace std;

int main () {
  int n,t,a[30010];
  cin >> n >> t;
  for (int i=1;i<n;i++) cin >> a[i];
  int i=1;
  while (i<t) i +=a[i];
  if (i==t) cout << "YES";
  else cout << "NO";
  cout << endl;


  return 0;
}
