class Solution {
public:
    /*
    At first consider first word in array as the answer
    the traverse the array from 2nd word
        update common prefix in each iteration
        at any point if common prefix becomes "", return
    at the end return ans
    */
    string updateCommonPrefix(string a, string b) {
        int i = 0, j = 0;
        string ans = "";

        // Taking the common prefix from strings a and b
        while(i < a.size() || j < b.size()) {
            if(a[i] == b[j]) {
                ans += a[i];
                i++;
                j++;
            }
            else {
                break;
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            ans = updateCommonPrefix(ans, strs[i]);

            if(ans == "") {
                break;
            }
        }
        return ans;
    }
};