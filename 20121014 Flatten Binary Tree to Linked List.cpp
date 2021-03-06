/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Discuss


*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        now = root;
        dfs(root);
    }
    TreeNode *now;
    void dfs(TreeNode *root) {
        if (!root) return;
        TreeNode *right = root->right;
        if (root->left) {
            now = now->right = root->left;
            dfs(root->left);
        }
        root->left = NULL;
        if (right) {
            now = now->right = right;
            dfs(right);
        }
    }
};