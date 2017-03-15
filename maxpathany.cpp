/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxsum = -0x7fffff;
    int path (TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = path(root->left);
        int right = path(root->right);
        left = max(0,left);
        right = max(0,right);
        int sum = left + right + root->val;
        maxsum = max(sum,maxsum);
        return max(left, right) + root->val;
    } 
     
    
    int maxPathSum(TreeNode *root) {
        // write your code here
        path(root);
        return maxsum;
    }
};
