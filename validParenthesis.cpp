bool match(char top,char exp){
  return (top == '(' && exp == ')') || (top == '{' && exp == '}') ||(top=='[' && exp==']');
}
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<expression.size();i++){
        if(st.empty()){
            st.push(expression[i]);
            continue;
        }
        if(match(st.top(),expression[i])){
            st.pop();
        }
        else{
            st.push(expression[i]);
        }
    }
    return st.size()==0;
}