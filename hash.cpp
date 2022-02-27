#include <bits/stdc++.h>
using namespace std;
class hashTable{
    private:
    static const int hashGroups =10;
    //list<pair<int,string>> table[hashGroups];
    list<pair<int,string>> table[hashGroups];

    public:
    bool isEmpty();
    int hashFunction(int key);
    void insertItem(int key,string value);
    void removeItem(int key);
    string searchItem(int key);
    void printTable();

};
bool hashTable::isEmpty(){
    int sum=0;
    for(int i=0;i<hashGroups;i++){
        sum=sum+table[i].size();

    }
    if(sum==0){
        return true;
    }else{
        return false;
    }
}
int hashTable::hashFunction(int key){
    return key%hashGroups;

}
void hashTable::insertItem(int key,string value){
    int hashValue=hashFunction(key);
    auto& cell=table[hashValue];
    auto itr=begin(cell);
    bool keyExists=false;
    for(; itr!=end(cell);itr++){
        if(itr->first==key){
            keyExists=true;
            itr->second=value;
            cout<<"key exists value replaced"<<endl;
            break;


        }
    }
    if(!keyExists){
        cell.emplace_back(key,value);
    }
    return;
}
void hashTable::removeItem(int key){
    int hashValue=hashFunction(key);
    auto& cell=table[hashValue];
    auto itr=begin(cell);
    bool keyExists=false;
    for(; itr!=end(cell);itr++){
        if(itr->first==key){
            keyExists=true;
            itr = cell.erase(itr);
            cout<<"item removed"<<endl;
            break;



        }
    }
    if(!keyExists){
        cout<<"Item not found Pair not removed"<<endl;
    }
    return;
}
void hashTable::printTable(){
    
    for(int i=0;i<hashGroups;i++){
        if(table[i].size()==0) continue;
        auto itr=table[i].begin();
        for(;itr!=table[i].end();itr++){
            cout<<"key"<<itr->first<<"value: "<<itr->second<<endl;

        }
    }
    return;
}

int main(){
    hashTable HT;
    if(HT.isEmpty()){
        cout<<"correct answer "<<endl;
    }else{
        cout<<"we need to chech out code!"<<endl;
    }
    HT.insertItem(1,"vaibhav");
    HT.insertItem(2,"mina");
    HT.insertItem(3,"steve");
    HT.insertItem(4,"sahil");
    HT.insertItem(5,"ruturaj");
    HT.insertItem(6,"vaibhav");
    HT.insertItem(7,"mina");
    HT.insertItem(8,"steve");
    HT.insertItem(9,"sahil");
    
    HT.removeItem(3);

    HT.printTable();


    return 0;
}