#include<bits/stdc++.h>
int lpscul(string str){
	int n=str.size();
	int lps[n]={0};
	int i=1;
	int len=0;
	while(i<n){
		if(str[i]==str[len]){
			len++;
			lps[i]=len;
			i++;

		}else{
			if(len!=0){
               len=lps[len-1];
			}else{
               lps[i]=0;
			   i++;
			}
		}
	}
	return lps[n-1];
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	string temp=str;
	reverse(temp.begin(),temp.end());
	int a=lpscul(str+"$"+temp);
	return str.size()-a;
	
}
