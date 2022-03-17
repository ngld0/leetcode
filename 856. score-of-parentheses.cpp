class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(auto c : s){
            
            if(c == '('){
                st.push(0);
            }else {
                int balance = st.top();
                st.pop();
                int val = 0;
                if(balance >0){
                    val = balance *2;
                }else {
                    val = 1;
                }
                st.top() += val; 
            }
        }
        return st.top();
    }
};
