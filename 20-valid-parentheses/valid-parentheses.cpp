class Solution {
public:
    bool matchingOpening(char open, char close) {
        return (open == '(' && close == ')') || 
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
    }
    bool isValid(string s) {
        if(s.size() & 1) {
            return false;
        }
        
        stack<int> st;

        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if(st.empty() || !matchingOpening(st.top(), ch)) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};