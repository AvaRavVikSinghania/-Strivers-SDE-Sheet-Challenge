#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    bool flag=true;
    string temp="";
    for(int i=0;i<str.size();i++){
        if(str[0]=='-'){
            flag=false;
        }
        if(str[i]>='0' && str[i]<='9'){
            temp+=str[i];
        }
    }
    int ans=0;
    for(int i=0;i<temp.size();i++){
        ans=ans*10;
        ans+=(temp[i]-'0');
    }
    if(!flag){
        ans=-1*ans;
    }
    return ans;
}