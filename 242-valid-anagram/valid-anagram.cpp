class Solution {
public:
    // M-2 : maintain a freq array
    /* Logic
    Maintain a freq array for each char in string 
    Update freq array for string s
    then for string t, decrement the freq count for each char while traversing
        (this will balance the freq count for both strings, and if at the end, 
        all the elements in freq array are 0 that means the strings are anagrams of
        each other)
    */
    bool isAnagram(string s, string t) {
        vector<int> freq (26, 0);

        // Incrementing freq count of characters in string s
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Decrementing freq count of characters in string t
        for(char ch : t) {
            freq[ch - 'a']--;
        }

        // If all elements of freq array are 0 -> true, else -> false
        for(int it : freq) {
            if(it != 0) {
                return false;
            }
        }
        return true;
    }

    // M-1 : Sort both strings and check if they are equal
    // bool isAnagram(string s, string t) {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());

    //     return s == t;
    // }
};