/*
algorithm

while(not destination node)
    find cheapest node();
    if(node has been tagged) continue;
    else tag this node;
    for(child node in this node)
        if(child node not been tagged yet)
            if(child weight + distance(root-parent) < distance(root-child))
                distance(root-child) = new distance;
                parent[child] = this node;
*/

/*
data struct

array for path
map<node, number>

node{
    vector<int> weight
    vector<node*> child_node
}
*/
#include <iostream>
#include <vector>
#include <map>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

struct Node{
    bool is_tagged = false;
    vector<int> weight;
    vector<Node*> child;
};

struct Path{
    int distance = 10000;
    int parent;
};

int FindCheapestNode(vector<pair<const int, Node*>>& ins){
    rep(i, ins.size()){
        if(ins[i].second->is_tagged == false) return i;
    }
    return 0;
}

int GetKey(vector<pair<const int, Node*>>& ins, Node* target){
    rep(i, ins.size()){
        if(ins[i].second == target) return ins[i].first;
    }
}

int main(){
    // init map ...
    Node* sheet  = new Node;
    Node* post   = new Node;
    Node* cd     = new Node;
    Node* kit    = new Node;
    Node* guitar = new Node;
    Node* piano  = new Node;

    sheet->child.push_back(post);
    sheet->child.push_back(cd);
    sheet->weight.push_back(0);
    sheet->weight.push_back(5);

    post->child.push_back(kit);
    post->child.push_back(guitar);
    post->weight.push_back(35);
    post->weight.push_back(30);

    cd->child.push_back(guitar);
    cd->child.push_back(kit);
    cd->weight.push_back(15);
    cd->weight.push_back(20);

    guitar->child.push_back(piano);
    guitar->weight.push_back(20);

    kit->child.push_back(piano);
    kit->weight.push_back(10);
    // ... end of init


    // start from sheet, end in piano

    // init hash map
    vector<pair<const int, Node*>> ins;
    ins.push_back(pair<const int, Node*>(0, sheet));
    ins.push_back(pair<const int, Node*>(1, post));
    ins.push_back(pair<const int, Node*>(2, cd));
    ins.push_back(pair<const int, Node*>(3, guitar));
    ins.push_back(pair<const int, Node*>(4, kit));
    ins.push_back(pair<const int, Node*>(5, piano));

    // init distance array
    vector<Path> path;
    Path new_ins;
    new_ins.distance = 0;
    new_ins.parent = -1;
    path.push_back(new_ins);

    rep(i, ins[0].second->child.size()){
        new_ins.distance = ins[0].second->weight[i];
        new_ins.parent   = 0;
        path.push_back(new_ins);
    }
    ins[0].second->is_tagged  = true;

    // algorithm implement
    int current_node = 0;
    int tmp = FindCheapestNode(ins);
    while(tmp){
        rep(i, ins[tmp].second->child.size()){
            new_ins.distance = ins[tmp].second->weight[i] + path[tmp].distance;
            new_ins.parent   = tmp;
            path.push_back(new_ins);

            if(ins[tmp].second->is_tagged) continue;
            else if(ins[tmp].second->weight[i] + path[tmp].distance 
                    < path[GetKey(ins, ins[tmp].second->child[i])].distance){
                path[GetKey(ins, ins[tmp].second->child[i])].parent = tmp;
                path[GetKey(ins, ins[tmp].second->child[i])].distance = ins[tmp].second->weight[i] + path[tmp].distance;
            }
        }
        ins[tmp].second->is_tagged = true;
        tmp = FindCheapestNode(ins);
    }

    // print ans path
    int i = path[path.size()-1].parent;
    vector<int> ans;
    while(-1 != i){
        ans.push_back(i);
        i = path[i].parent;
    }
    for(int i = ans.size()-1; i >= 0; --i){
        cout << ans[i] << "->";
    }
    cout << 5 << endl;
    cout << "Total distance is " << path[path.size()-1].distance << endl;
    
    return 0;
}