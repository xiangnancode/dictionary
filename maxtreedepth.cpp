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
     
    
    
    int dfs (TreeNode *root, int dep){
        if (root == NULL){
            return dep;
        }
        int ldep = 0, rdep = 0;
        dep++;
        
        ldep = dfs(root->left, dep);
        rdep = dfs(root->right, dep);
        
        if (ldep > rdep){
            return ldep;
        }
        else{
            return rdep;
        }
    }
     
    int maxDepth(TreeNode *root) {
        // write your code here
        int maxdep = 0;
        maxdep = dfs(root,maxdep);
        
        return maxdep;

    }
};


// solution

    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;

    }

