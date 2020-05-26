/* Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000. */


/* Approach - use presum and hash map */

// Time Complexity - O(n), where n is length of nums vector
// Space Complexity - O(n)

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> lastIndex;
        int sum = 0, maxLength = 0;
        lastIndex[0] = -1;
        for ( int i = 0; i < nums.size(); i++) {
            sum += nums[i] ? 1 : -1;
            if (lastIndex.count(sum)) {
                maxLength = max(maxLength, i - lastIndex[sum]);
            }
            else{
                lastIndex[sum] = i;
            }
        }
        return maxLength;
    }
};