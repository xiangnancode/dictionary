#include <iostream>
#include <vector>
#include <queue>

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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    vector<char> v;

    void traverse(TreeNode *root) {
        if (root == NULL) {
            v.push_back('#');
            return;
        }
        
        traverse(root->left);
        char value = '0' + root->val;
        v.push_back(value);
        traverse(root->right);
    }
    vector< vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        TreeNode *head;
        vector< vector<int> > ans;
        vector<int> level;
        queue<TreeNode *> Q;
        if (root == NULL) {
            return ans;
        }
        Q.push(root);
        while (!Q.empty()) {
            int width = Q.size();
            for (int i = 0; i < width; i++) {
                head = Q.front();
                Q.pop();
                if (head->left != NULL) {
                    Q.push(head->left);
                }
                if (head->right != NULL) {
                    Q.push(head->right);
                }
                level.push_back(head->val);
                //cout << head->val << " ";
            }
            ans.push_back(level);
            level.clear();
            //cout << endl;
        }
        return ans;
    }

    TreeNode* remove(TreeNode *node, int value) {
        if (node == NULL) {
            return node;
        }
        if (value < node->val) {
            node->left = remove(node->left, value);
        } else if (value > node->val) {
            node->right = remove(node->right, value);
        } else {
            if (node->left == NULL && node->right == NULL) {
                node = NULL;
            } else if (node->left == NULL) {
                node = node->right;
            } else if (node->right == NULL) {
                node = node->left;
            } else {
                TreeNode *parent = node;
                TreeNode *successor = node->right;
                while (successor->left != NULL) {
                    parent = successor;
                    successor = successor->left;
                }
                node->val = successor->val;
                if (parent == node) {
                    node->right = successor->right;
                }
                parent->left = successor->right;
            }
        }
        return node;
    }
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        root = remove(root, value);
        return root;
    }
};

void test(TreeNode** t) {
    Solution x;
    x.v.clear();
    x.traverse(*t);
    for (int i = 0; i < x.v.size(); ++i)
    {
        cout << x.v[i] << " ";
    }
    cout << endl;
    *t = NULL;
    x.v.clear();
    x.traverse(*t);
    for (int i = 0; i < x.v.size(); ++i)
    {
        cout << x.v[i] << " ";
    }
    cout << endl;
}

int main(){
    Solution x;
    TreeNode a(2);
    TreeNode R(4);
    TreeNode RL(3);
    TreeNode L(1);
    TreeNode* root;
    root = &a;
    root->left = &L;
    root->right = &R;
    root->right->left = &RL;
    vector< vector<int> > out;

    /*out = x.levelOrder(root);

    cout << out.size() << endl;

    for (int i = 0; i < out.size(); ++i)
    {
        for (int j = 0; j < out[i].size(); ++j)
        {
            cout << out[i][j] << " ";        
        }
        cout << endl;
    }
    cout << endl;*/
    //x.removeNode(root,2);
    test(&root);
    x.v.clear();
    x.traverse(root);

    for (int i = 0; i < x.v.size(); ++i)
    {
        cout << x.v[i] << " ";
    }
    cout << endl;

}
