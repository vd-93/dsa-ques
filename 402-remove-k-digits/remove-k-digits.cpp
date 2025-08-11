/* Logic :
Use a monotonic increasing stack to maintain the digits that will form the final number.
While iterating through string 'num'. If the current digit is smaller than the top of the stack, remove the top of the stack (if k > 0). 
Push the current digit onto the stack.

edge cases :1) k == num's size -> return "0"
    2) result string has leading 0s -> remove leading zeros
    3) even after traversing the string, k is still greater than 0 -> remove last k elements
        (in case the digits in num are in increasing order)
*/
class Solution {
public:
    // M-1
    string removeKdigits(string num, int k) {
        string res = "";
        string ans = "";

        for(int i = 0; i < num.size(); i++) {
            while(!res.empty() && k > 0 && (int)res.back() > (int)num[i]) {
                res.pop_back();
                k--;
            }
            res.push_back((char)num[i]);
        }

        // Is k is still greater than 0, remove the last k elements
        while(k) {
            res.pop_back();
            k--;
        }

        bool leadingZeros = true;

        for(char ch : res) {
            if(leadingZeros && ch == '0') {
                continue;
            }
            leadingZeros = false;
            ans.push_back(ch);
        }

        if(ans.empty()) return "0";
        return ans;
    }
};