/* In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100. */


/* Approach - DFS traversal of tree */

// Time Complexity - O(n), where n is number of nodes in tree
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
public:
    void dfs(TreeNode *root, int target, int &parent, int &height, int currHeight){
        if(root){
            dfs(root->left, target, parent, height, currHeight + 1);
            if (root->left && root->left->val == target){
                parent = root->val;
                height = currHeight + 1;
            }
            if (root->right && root->right->val == target){
                parent = root->val;
                height = currHeight + 1;
            }
            dfs(root->right, target, parent, height, currHeight + 1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root || root->val==x || root->val==y) {
            return false;
        }
        int parentX, parentY;
        int heightX, heightY;
        dfs(root, x, parentX, heightX, 0);
        dfs(root, y, parentY, heightY, 0);
        return heightX == heightY && parentX != parentY;
    }
};