#include<bits/stdc++.h>
using namespace std;
class LRU1{
    public:
    vector<pair<int,int>>cache;
    int n;
    LRU1(int size){
        n=size;
    }
    int get(int key){
        int value=-1;
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
               value=cache[i].second; 
               cache.erase(cache.begin()+i);
               cache.push_back({key,value});
            }
        }
        return value;
    }
    void put(int key,int value){
        for(int i=0;i<cache.size();i++){
            if(cache[i].first==key){
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return ;
            }
        }
        if(cache.size()==n){
           cache.erase(cache.begin());
           cache.push_back({key,value});
        }else{
            cache.push_back({key,value});
        }
    }
};
class LRU2{
    public:
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRU2(int size){
        this->n=size;
    }
    void  makeRecentlyUsed(int key){
         dll.erase(mp[key].first);//address
         dll.push_front(key);
         mp[key].first=dll.begin();
    }
    int get(int key){
        if(mp.find(key)==mp.end()) return -1;
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    void put(int key,int value){
        if(mp.find(key)!=mp.end()){
           mp[key].second=value;
           makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            int key_toBedelated=dll.back();
            mp.erase(key_toBedelated);
            dll.pop_back();
            n++;
        }
    }
};
int main(){

}