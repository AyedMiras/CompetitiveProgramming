#include <iostream>

using namespace std;

int main () {
  int m,s;
  cin >> m >> s;
  if ((!s & m!=1 )|| s>9*m) cout << "-1 -1" <<  endl;
  else if (m==1) cout << s <<" "<< s << endl;
  else{
    int s2=s;
    cout << s%9;
    s -=s%9;
    for (int i=1;i<m;i++){
      if (s/9 < m-i) cout << 0;
      else {
        cout << 9;
      }
    }
    cout << " ";
    for (int i=0;i<m;i++) {
      if (s2>=9) {
        cout << 9;
        s2-=9;
      }
      else {
        cout << s2;
        s2=0;
      }
    }
    cout<<endl;
  }


  return 0;
}
