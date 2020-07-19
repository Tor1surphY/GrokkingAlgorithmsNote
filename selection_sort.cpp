#include <iostream>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main(){
    int a[10] = { 87, 22, 98, 0, 12, 7, 72, 33, 30, 77 };
    int tmp = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = i; j < 10; ++j){
            if(a[i] > a[j]){
                tmp  = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    rep(i, 10) cout << a[i] << ' ';
    cout << endl;
    return 0;
}