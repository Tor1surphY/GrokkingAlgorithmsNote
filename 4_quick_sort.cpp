#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

void Swap(int* num, int a, int b){
    int tmp = num[a];
    num[a] = num[b];
    num[b] = tmp;
}

void QuickSort(int* num, int left, int right){
    // base case为当左值>=右值的时候
    if(left >= right) return;
    
    int tag = left;
    int i = left+1;
    int tmp = right+1;
    // 寻找第一个比tag大的数tmp
    for(i; i <= right; ++i){
        if(num[i] > num[tag]){
            tmp = i;
            break;
        }
    }
    
    // 找比tag小的num[j]，让它和tmp换位置，换了之后tmp要后移
    // 这一步保证了所有比tag小的数，全在当前tmp的左边
    for(int j = tmp+1; j <= right; ++j){
        if(num[j] < num[tag]){
            Swap(num, j, tmp);
            ++tmp;
        }
    }
    // 把tag和当前tmp左边交换位置
    // 至此，实现了第一次递归，分为了left，tag，right三部分
    Swap(num, tag, tmp-1);
    // 这一步多余的，目的是方便理解
    tag = tmp-1;
    QuickSort(num, left, tag-1);
    QuickSort(num, tag+1, right);
}

void QuickSortVer2(vector<int>& num){
    if(0 == num.size()){
        cout << "";
        return;
    }
    if(1 == num.size()){
        cout << num[0] << ' ';
        return;
    }

    int tag = num[0];
    vector<int> left;
    vector<int> right;
    rep(i, num.size()){
        if(num[i] < tag) left.push_back(num[i]);
        if(num[i] > tag) right.push_back(num[i]);
    }
    QuickSortVer2(left);
    cout << tag << ' ';
    QuickSortVer2(right);
}

int main(){
    /*
    srand((unsigned int) time(NULL));
    int num[10];
    rep(i, 10) num[i] = rand()%100;
    rep(i, 10) cout << num[i] << ' ';
    cout << endl;
    QuickSort(num, 0, 9);
    rep(i, 10) cout << num[i] << ' ';
    cout << endl;
    */

    srand((unsigned int) time(NULL));
    vector<int> num(10);
    rep(i, 10) num[i] = rand()%100;
    rep(i, 10) cout << num[i] << ' ';
    cout << endl;
    QuickSortVer2(num);
    cout << endl;

    return 0;
}
