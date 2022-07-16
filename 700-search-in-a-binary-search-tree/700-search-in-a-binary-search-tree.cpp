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
    void solver(TreeNode* root,int val, TreeNode* &ans){
        if(root == NULL)
            return;
        
        if(root->val == val){
            ans = root;
            return;
        }
        
        if(val > root->val)
            solver(root->right,val,ans);
        
        else
            solver(root->left,val,ans); 
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        solver(root,val,ans);
        return ans;
    }
};