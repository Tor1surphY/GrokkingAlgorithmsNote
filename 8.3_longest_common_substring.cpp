#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int main(){
    string str1 = "fish";
    string str2 = "hish";
    vector<vector<int>> ans(str1.size(), vector<int>(str2.size()));

    rep(i ,str1.size()){
        rep(j, str2.size()){
            if(str1[i] == str2[j]){
                if(i == 0 || j == 0) ++ans[i][j]; 
                else ans[i][j] += 1 + ans[i-1][j-1];
            }
        }
    }
    cout << ans[str1.size()-1][str2.size()-1] << endl;

    return 0;
}
