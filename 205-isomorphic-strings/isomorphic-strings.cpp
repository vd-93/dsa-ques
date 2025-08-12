class Solution {
public:
    // M-2
    /* since both s and t can contain any valid ASCII character (0–127), 
    we can use fixed-size arrays instead of unordered_map for better performance.
    */
    bool isIsomorphic(string s, string t) {
        // Default values are 0, which we use to indicate "unmapped".
        int mapST[128] = {0}; // s[i] → t[i]
        int mapTS[128] = {0}; // t[i] → s[i]

        for(int i = 0; i < s.size(); i++) {
            char chS = s[i];
            char chT = t[i];

            // If no mapping exists, set it
            if(mapST[chS] == 0 && mapTS[chT] == 0) {
                mapST[chS] = chT;
                mapTS[chT] = chS;
            }
            // If mapping exists, check consistency
            else if (mapST[chS] != chT || mapTS[chT] != chS) {
                return false;
            }
        }

        return true;
    }

    // M-1
    // bool isIsomorphic(string s, string t) {
    //     unordered_map<char, char> mapST; // mapping from s to t
    //     unordered_map<char, char> mapTS; // mapping from t to s

    //     for (int i = 0; i < s.size(); i++) {
    //         char chS = s[i];
    //         char chT = t[i];

    //         // Check if mapping from s -> t is consistent
    //         if (mapST.count(chS)) {
    //             if (mapST[chS] != chT) {
    //                 return false;
    //             }
    //         } else {
    //             mapST[chS] = chT;
    //         }

    //         // Check if mapping from t -> s is consistent
    //         if (mapTS.count(chT)) {
    //             if (mapTS[chT] != chS) {
    //                 return false;
    //             }
    //         } else {
    //             mapTS[chT] = chS;
    //         }
    //     }
    //     return true;
    // }
};