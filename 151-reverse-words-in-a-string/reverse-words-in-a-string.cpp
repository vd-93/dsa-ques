class Solution {
public:
    /* M-2
    Logic
    1. Reverse the entire string
    2. Get each word, move it to its right place by moving it to left 
        (removing any unnecessary leading spaces)
    3. Reverse that word
    */
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());

        int i = 0, j = 0, start = 0;

        while (j < n) {
            // Getting the starting index of a word
            while (j < n && s[j] == ' ') {
                j++;
            }
            if (j == n) {
                break;
            }

            // Adding space before a word if it is not the first word
            if (i != 0) {
                s[i++] = ' ';
            }
            
            // start index of current word in final string
            int start = i;
            
            // Moving the word to its correct position
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }

            // Reversing the current word
            reverse(s.begin() + start, s.begin() + i);
        }
        // At this point i will be pointing to the (last non space char + 1)th index
        return s.substr(0, i);
    }

    // M-1 SC - O(N)
    // string reverseWords(string s) {
    //     stack<string> st;
    //     string res;
    //     string word;

    //     // Adding each word to stack
    //     for(char ch : s) {
    //         if(ch == ' ') {
    //             if(word.size() != 0) {
    //                 st.push(word);
    //             }
    //             word = "";
    //             continue;
    //         }

    //         word += ch;
    //     }

    //     // The last word of the string after traversing the string
    //     if(word.size()) {
    //         st.push(word);
    //     }

    //     while(!st.empty()) {
    //         res += st.top();
    //         st.pop();
    //         // Adding space after each word except for last word
    //         if(!st.empty()) {
    //             res += " ";
    //         }
    //     }

    //     return res;
    // }
};