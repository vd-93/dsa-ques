class Solution {
public:
    bool isOpeningBracket(char b) {
        return b == '(' || b == '[' || b == '{';
    }

    bool matches(char a, char b) {
        return (a == '(' && b == ')') || 
               (a == '[' && b == ']') || 
               (a == '{' && b == '}'); 
    }

    bool isValid(string s) {
        // If the string length is odd, it can't be a valid set of brackets
        if (s.length() & 1) return false;   

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isOpeningBracket(ch)) {
                // Push opening brackets onto the stack
                st.push(ch);
            } else {
                // If a closing bracket is found but the stack is empty, it's invalid
                if (st.empty()) {
                    return false;
                }

                // Check if the top of the stack matches the current closing bracket
                if (matches(st.top(), ch)) {
                    st.pop(); // Valid match, pop the opening bracket
                } else {
                    return false; // Mismatch found
                }
            }
        }

        // If the stack is empty, all brackets were matched correctly
        return st.empty();
    }
};
