/* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3  */


/* Approach - use dfs traversal */

// Time Complexity - O(n), where n is no of nodes in tree
// Space Complexity - O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* root, int &k, int &number){
        if (root) {
            dfs(root->left, k, number);
            if ( --k == 0) {
                number = root->val;
            }
            dfs(root->right, k, number);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int number;
        dfs(root, k, number);
        return number;
    }
};