class Solution {
public:
    // M-2 O(N)
    /* We keep track of the balance between '(' and ')' using a counter.
    We skip adding the first '(' and the last ')' of each primitive (when balance is 0
    just before and just after).
    */
    string removeOuterParentheses(string s) {
        string res;
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                // skip outermost '('
                if (count > 0) {
                    res += ch;
                }
                count++;
            } else {
                count--;
                // skip outermost ')'
                if (count > 0) {
                    res += ch;
                }
            }
        }

        return res;
    }

    // M-1 : O(2N)
    // string removeOuterParentheses(string s) {
    //     string res;
    //     int i = 0;
    //     int openCnt = 0;
    //     int closedCnt = 0;
    //     for(int j = 0; j < s.size(); j++) {
    //         if(s[j] == '(') {
    //             openCnt++;
    //         }
    //         else {
    //             closedCnt++;
    //         }

    //         if(openCnt == closedCnt) {
    //             for(int k = i + 1; k < j; k++) {
    //                 res += s[k];
    //             }
    //             openCnt = 0;
    //             closedCnt = 0;
    //             i = j + 1;
    //         }
    //     }

    //     return res;
    // }
};