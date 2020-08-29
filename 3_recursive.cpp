#include <iostream>
using namespace std;

void Count(int cnt){
    cout << cnt << " ";
    if(cnt > 0) Count(--cnt);
    else return;
}


int main(){
    Count(10);
    cout << endl;
    return 0;
}
