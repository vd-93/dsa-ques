class Solution {
public:
    // M-1
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapST; // mapping from s to t
        unordered_map<char, char> mapTS; // mapping from t to s

        for (int i = 0; i < s.size(); i++) {
            char chS = s[i];
            char chT = t[i];

            // Check if mapping from s -> t is consistent
            if (mapST.count(chS)) {
                if (mapST[chS] != chT) {
                    return false;
                }
            } else {
                mapST[chS] = chT;
            }

            // Check if mapping from t -> s is consistent
            if (mapTS.count(chT)) {
                if (mapTS[chT] != chS) {
                    return false;
                }
            } else {
                mapTS[chT] = chS;
            }
        }
        return true;
    }
};