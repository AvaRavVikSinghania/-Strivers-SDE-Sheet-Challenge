#include <bits/stdc++.h> 
void f(int i,string &s,string temp, vector<string>&ans,map<string,bool>mp){
    if(i==s.size()){
        ans.push_back(temp);
        return ;
    }
    for(int index=i;index<s.size();index++){
        if(mp.find(s.substr(i,index-i+1))!=mp.end()){
            f(index+1,s,temp+s.substr(i,index-i+1)+" ",ans,mp);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here 
    map<string,bool>mp;
    for(auto it:dictionary){
        mp[it]=true;
    }
    vector<string>ans;
    f(0,s,"",ans,mp);
    return ans;
}