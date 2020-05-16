/* Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2 */


/* Approach - Use hash map */

// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int n : nums) {
            count[n]++;
            if (count[n] > nums.size() / 2) {
                return n;
            }
        }
        return -1;
    }
};