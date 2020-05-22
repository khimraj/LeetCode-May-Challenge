/* Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters. */


/* Approach - Use hash map and bucket sort */

// Time Complexity - O(n), where n is length of string s
// Space Complexity - O(n)

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> countMap;
        vector<string> bucket(s.size() + 1, "");
        string sortedS = "";
        for (char c : s) {
            countMap[c]++;
        }
        for (auto itr : countMap) {
            bucket[itr.second].append(itr.second, itr.first);
        }
        for (int i = s.size(); i > 0; i--) {
            sortedS += bucket[i];
        }
        return sortedS;
    }
};