/* Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters. */


/* Approach - Use hash map */

// Time Complexity - O(n), where n = length of s
// Space Complexity - O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        for (char c : s) {
            count[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};