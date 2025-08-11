class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string res;
        string word;

        // Adding each word to stack
        for(char ch : s) {
            if(ch == ' ') {
                if(word.size() != 0) {
                    st.push(word);
                }
                word = "";
                continue;
            }

            word += ch;
        }

        // The last word of the string after traversing the string
        if(word.size()) {
            st.push(word);
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
            // Adding space after each word except for last word
            if(!st.empty()) {
                res += " ";
            }
        }

        return res;
    }
};