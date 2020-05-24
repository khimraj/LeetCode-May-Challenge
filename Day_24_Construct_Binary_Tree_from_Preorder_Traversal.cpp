/* Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Constraints:

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
The values of preorder are distinct. */


/* Approach - recursion */

// Time Complexity - O(n), where n is length of preorder vector
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
    TreeNode* treeBuilder(vector<int> preorder, int start, int end){
        if (end < start) {
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[start]);
        int index = start;
        while (index <= end && preorder[index] <= preorder[start]) {
            index++;
        }
        root->left = treeBuilder(preorder, start + 1, index - 1);
        root->right = treeBuilder(preorder, index, end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return treeBuilder(preorder, 0, preorder.size() - 1);
    }
};