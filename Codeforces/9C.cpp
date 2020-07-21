#include <iostream>
#include <stdlib.h>
using namespace std;

int N,res;
char bin[11];

int loaded (const int& k) {
    if (k==10) {
        if (atoi(bin) <= N)
            res++;
    }

    else {
        bin[k]='1';
        loaded(k+1);
        bin[k]='0';
        loaded(k+1);
    }
}

int main (){
    cin >> N;
    loaded(0);
    cout << res-1 << endl;
    return 0;
}
