class Solution {
public:
    // M-2 : Doubling the string s and checking if goal is present in s + s
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) {
            return false;
        }

        string doubledString = s + s;

        return doubledString.find(goal) != string::npos;
    }

    // M-1 : Try all possible rotations of s O(N^2)
    // bool rotateString(string s, string goal) {
    //     if(s.size() != goal.size()) {
    //         return false;
    //     }

    //     for(int i = 0; i < s.size(); i++) {
    //         string rotated = s.substr(i) + s.substr(0, i);

    //         if(rotated == goal) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};