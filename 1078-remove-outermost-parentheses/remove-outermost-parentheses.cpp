class Solution {
public:
    // M-1 : O(2N)
    string removeOuterParentheses(string s) {
        string res;
        int i = 0;
        int openCnt = 0;
        int closedCnt = 0;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '(') {
                openCnt++;
            }
            else {
                closedCnt++;
            }

            if(openCnt == closedCnt) {
                for(int k = i + 1; k < j; k++) {
                    res += s[k];
                }
                openCnt = 0;
                closedCnt = 0;
                i = j + 1;
            }
        }

        return res;
    }
};