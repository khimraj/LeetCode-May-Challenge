/* Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc". */


/* Approach - use sliding window */

// Time Complexity - O(n), where n is size of s
// Space Complexity - O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indicesArray;
        if (s.size() < p.size()) {
            return indicesArray;
        }
        vector<int> pCount(26,0);
        for (char c : p) {
            pCount[c - 'a']++;
        }
        vector<int> sCount(26,0);
        for (int j = 0; j < p.size(); j++) {
            sCount[s[j] - 'a']++;
        }
        int equal = 1;
        for (int j = 0; j < 26; j++) {
            if (sCount[j] != pCount[j]) {
                equal = 0;
                break;
            }
        }
        if (equal) {
            indicesArray.push_back(0);
        }
        for ( int i = 1; i <= s.size() - p.size(); i++) {
            sCount[s[i - 1] - 'a']--;
            sCount[s[i + p.size() - 1] - 'a']++;
            equal = 1;
            for (int j = 0; j < 26; j++) {
                if (sCount[j] != pCount[j]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                indicesArray.push_back(i);
            }
        }
        return indicesArray;
    }
};