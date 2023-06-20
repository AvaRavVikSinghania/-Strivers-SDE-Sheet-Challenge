#include <bits/stdc++.h> 
void sortstack(stack<int>&s){
	if(s.empty()){
		return;
	}
    int x = s.top();
    s.pop();
    sortstack(s);
    stack<int> tempStack;
     
   
    while (!s.empty() && s.top() > x) {
        tempStack.push(s.top());
        s.pop();
    }
     
    s.push(x);
     
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()||stack.size()==1) return ;
    sortstack(stack);
	return ;
}