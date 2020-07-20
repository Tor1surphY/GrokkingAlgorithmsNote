#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i, n) for(int i = 1; i < (n); ++i)
using namespace std;

int main(){
    string str1 = " fosh";
    string str2 = " fish";
    vector<vector<int>> ans(str1.size(), vector<int>(str2.size()));

    rep(i ,str1.size()){
        rep(j, str2.size()){
            if(str1[i] == str2[j]) ans[i][j] = (1 + ans[i-1][j-1]);
            else ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
    }
    cout << ans[str1.size()-1][str2.size()-1] << endl;
    return 0;
}