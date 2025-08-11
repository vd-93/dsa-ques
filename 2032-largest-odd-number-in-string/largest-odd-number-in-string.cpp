class Solution {
public:
    // Logic : answer will be the number from start to the rightmost odd digit
    string largestOddNumber(string num) {
        int i = num.size() - 1;

        while(i >= 0) {
            if((int)num[i] % 2 == 0) {
                i--;
            }
            else {
                break;
            }
        }
        // At this point i will be pointing to the right most odd digit
        // OR to -1 if no odd digit is present in num

        return num.substr(0, i + 1);
    }
};