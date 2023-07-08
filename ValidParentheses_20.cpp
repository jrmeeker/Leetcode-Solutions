/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */


class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;

        std::stack<int> st;
        for(auto ch:s)
        {
            if(ch == '(')
                st.push(')');
            else if(ch == '[')
                st.push(']');
            else if(ch == '{')
                st.push('}');            
            else{
                if(st.empty() || st.top() != ch)
                    return false;               
                st.pop();
            }
        }
        return st.empty();
    }
};