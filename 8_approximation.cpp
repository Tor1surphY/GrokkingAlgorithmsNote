#include <iostream>
#include <string>
#include <vector>

using namespace std;

int operator&(vector<string> str1, vector<string> str2){
    int ans = 0;
    for(auto idx : str1){
        for(auto i : str2){
            if(i == idx){
                ++ans;
                break;
            }
        }
    }
    return ans;
}

void EraseTaggedChannel(vector<string>& tmp, vector<string>& tagged_provience){
    for(auto idx : tmp){
        for(int i = 0; i < tagged_provience.size(); ++i){
            if(tagged_provience[i] == idx){
                tagged_provience.erase(tagged_provience.begin()+i);
                break;
            }
        }
    }
}

void Print(vector<string> tmp){
    for(auto idx : tmp) cout << idx << ' ';
    cout << endl;
}

int main(){
    vector<vector<string>> channel_set(5);
    channel_set[0] = {"id", "nv", "ut"};
    channel_set[1] = {"wa", "id", "mt"};
    channel_set[2] = {"or", "nv", "ca"};
    channel_set[3] = {"nv", "ut"};
    channel_set[4] = {"ca", "az"};

    vector<string> tagged_provience = 
        {"id", "nv", "ut", "wa", "mt", "or", "ca", "az"};

    // data struct:
    //   vector<int> best_channel_set
    //   vector<string> tagged_provience
    // algorithm:
    //   for(every channel in channel_set)
    //       find the biggest channel in channel set
    //       erase this channel set from tagged_channel
    //       rease channel that has been tagged
    //       add this channel to best_channel_set
    //       delete this channel from channel set
    // O(N^2)

    vector<vector<string>> best_channel_set;
    int tagged_num;
    int cmp = 0;
    int rcd = 0;
    vector<string> tmp;
    int channel_num = 0;

    while(tagged_provience.size() != 0){
        for(int idx = 0; idx < channel_set.size(); ++idx){
            tagged_num = channel_set[idx] & tagged_provience;
            if(tagged_num > cmp){
                tmp = channel_set[idx];
                cmp = tagged_num;
                rcd = idx;
            }
        }
        cmp = 0;
        EraseTaggedChannel(tmp, tagged_provience);
        channel_set.erase(channel_set.begin()+rcd);
        best_channel_set.push_back(tmp);
        channel_num += tmp.size();
    }
    for(auto idx : best_channel_set) Print(idx);
    cout << endl;
    cout << channel_num << endl;
    return 0;
}

// 对于这道题，最优解是1, 2, 3, 4, channel_num = 10
// 贪心算法的结果是0, 1, 2, 4, channel_num = 11

