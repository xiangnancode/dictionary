#include <iostream>
#include <vector>

using namespace std;

 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };
 

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
         vector<int> preorder;

    void traverse(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        preorder.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};

void initree(TreeNode *root){
    root->val = 1;
    TreeNode R(2);
    TreeNode RL(3);
    //R->val = 2;
    //RL->val = 3;
    R.left = &RL;
    root->right = &R;

}

int main(){
    Solution x;
    vector<int> v;
    TreeNode root(0);
    //root.val = 1;
    //root.val = 5;

    cout << root.val << endl;
    initree(&root);

    x.traverse(&root);

    //cout << v.size() << endl;

    for (int i = 0; i < x.preorder.size(); ++i)
    {
        cout << x.preorder[i] << " ";
    }
    cout << endl;
}

