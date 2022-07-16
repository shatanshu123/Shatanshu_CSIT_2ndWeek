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
    void ins(TreeNode*& node, int val) {
       if(node == nullptr) node = new TreeNode(val);
       else if(node->val > val) ins(node->left, val);
       else ins(node->right, val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        ins(root, val);
        return root;
    }
};