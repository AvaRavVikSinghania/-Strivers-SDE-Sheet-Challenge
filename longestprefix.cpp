class Node{
    public:
    Node* links[26];
    int cnt=0;
    bool iscontains(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void countincreased(){
        cnt++;
    }
    int getcount(){
        return cnt;
    }

};
class Trie{
   private: Node* root;
   public:
    Trie(){
        root=new Node();
    }
    void insert(string word,int n){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->iscontains(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->countincreased();
            if(node->getcount()!=n){
                break;
            }

        }
    }
    string getprefixmax(string word,int n){
        Node* node=root;
        string ans="";
        for(int i=0;i<word.size();i++){
            if(node->iscontains(word[i])){
               node=node->get(word[i]);
               if(node->getcount()==n){
                   ans+=word[i];
               }else{
                   break;
               }
            }
            else{
                break;
            }
        }
        return ans;
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie trie;
    string minimum_length="";
    for(int i=0;i<n;i++){
        if(minimum_length.size()<arr[i].size()){
            minimum_length=arr[i];
        }
        trie.insert(arr[i],i+1);
    } 
    if(minimum_length.size()==0) return "";
    return trie.getprefixmax(minimum_length,n);
}


