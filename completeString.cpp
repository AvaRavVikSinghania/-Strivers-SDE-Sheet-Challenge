#include <bits/stdc++.h> 
struct Node
{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: Node* root;
    public:
    Trie(){
       root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
              node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkallprefixExit(string &word){
      Node* node=root;
      bool flag=true;
      for(int i=0;i<word.size();i++){
          if(node->containsKey(word[i])){
               node=node->get(word[i]);
               flag=flag & node->isEnd();
          }else{
            return false;
          }
      }   
       return flag;
    }

};
string completeString(int n, vector<string> &arr){
    // Write your code here.
    Trie trie;
    for(auto &it:arr){
        trie.insert(it);
    }
    string langest="";
    for(auto &it:arr){
       if(trie.checkallprefixExit(it)){
        if(it.size()>langest.size()){
           langest=it;
        }
        else if(it.size()==langest.size() && it<langest ){
            langest=it;
        }
       }
    }
    if(langest.size()==0) return "None";
    return langest;
}