/* Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000]. */


/* Approach - use sliding window */

// Time Complexity - O(n), where n is length of s2
// Space Complexity - O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        vector<int> s1Count(26,0);
        for (char c : s1) {
            s1Count[c - 'a']++;
        }
        vector<int> s2Count(26,0);
        for (int j = 0; j < s1.size(); j++) {
            s2Count[s2[j] - 'a']++;
        }
        int equal = 1;
        for (int j = 0; j < 26; j++) {
            if (s2Count[j] != s1Count[j]) {
                equal = 0;
                break;
            }
        }
        if (equal) {
            return true;
        }
        for ( int i = 1; i <= s2.size() - s1.size(); i++) {
            s2Count[s2[i - 1] - 'a']--;
            s2Count[s2[i + s1.size() - 1] - 'a']++;
            equal = 1;
            for (int j = 0; j < 26; j++) {
                if (s2Count[j] != s1Count[j]) {
                    equal = 0;
                    break;
                }
            }
            if (equal) {
                return true;
            }
        }
        return false;
    }
};