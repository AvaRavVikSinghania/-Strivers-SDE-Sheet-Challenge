#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	if(n==1) return "1";
	if(n==2) return "11";
	string str="11";
	for(int j=3;j<=n;j++){
        string temp="";
		int cnt=1;
		char ch=str[0];
		for(int i=1;i<str.size();i++){
            if(ch==str[i]){
				cnt++;
			}
			else{
				temp+=(cnt+'0');
				temp+=ch;
				ch=str[i];
				cnt=1;
			}
		}
		temp+=(cnt+'0');
		temp+=ch;
		str=temp;
	}
	return str;	
}