#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i ,n) for(int i = 0; i < (n); ++i)

int SumOfNumbers(vector<int> num){
    if(1 == num.size()) return num[0];
    int tmp = num[num.size()-1];
    num.pop_back();
    return tmp + SumOfNumbers(num);
}

int SizeOfVector(vector<int> num){
    if(1 == num.size()) return 1;
    num.pop_back();
    return 1 + SizeOfVector(num);
}

int FindBiggestNumber(vector<int> num){
    if(2 == num.size()) return max(num[0], num[1]);
    int cmp = num[num.size()-1];
    num.pop_back();
    return max(cmp, FindBiggestNumber(num));
}

int main(){
    vector<int> num(5);
    rep(i, 5) cin >> num[i];
    cout << "SumOfNumbers: "      << SumOfNumbers(num) << endl;
    cout << "SizeOfVector: "      << SizeOfVector(num) << endl;
    cout << "FindBiggestNumber: " << FindBiggestNumber(num) << endl;
    return 0;
}
