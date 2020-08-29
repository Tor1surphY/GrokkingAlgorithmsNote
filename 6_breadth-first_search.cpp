#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{

public:
    Person(string name, bool is_seller)
    : _name(name)
    , _is_seller(is_seller){}

    void AddFriend(Person* new_friend){
        _my_friend.push_back(new_friend);
    }

    bool IsSeller() const{
        return _is_seller;
    }

    vector<Person*> GetFriends() const{
        return _my_friend;
    }

    string GetName() const{
        return _name;
    }


private:
    string _name;
    bool _is_seller;
    // an pointer arr point to class Person
    vector<Person*> _my_friend;
};

int main(){
    // 构建图
    Person* myself  = new Person("myself",  0);
    Person* luffy   = new Person("luffy",   0);
    Person* nami    = new Person("nami",    1);
    Person* zoro    = new Person("zoro",    0);
    Person* sanji   = new Person("sanji",   1);
    Person* ussoppu = new Person("ussoppu", 0);
    myself->AddFriend(luffy);
    myself->AddFriend(nami);
    luffy->AddFriend(zoro);
    luffy->AddFriend(sanji);
    luffy->AddFriend(ussoppu);

    vector<Person*> queue;
    queue.push_back(myself);

    Person* to_be_delete;
    while(0 != queue.size()){
        if(queue[0]->IsSeller()){
            cout << queue[0]->GetName() << " is a seller." << endl;
            
        }
        else{
            for(int i = 0; i < queue[0]->GetFriends().size(); ++i){
                queue.push_back(queue[0]->GetFriends()[i]);
            }
        }
        to_be_delete = queue[0];
        queue.erase(queue.begin());
        delete to_be_delete;
    }
    to_be_delete = nullptr;
    
    return 0;
}
