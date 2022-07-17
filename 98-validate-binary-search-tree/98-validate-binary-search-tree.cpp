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
    vector<int>temp;
    void recurr(TreeNode* root){
        if(root==NULL)
            return;
        else{
            recurr(root->left);
            temp.push_back(root->val);
            recurr(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        recurr(root);
        for(int i=1;i<temp.size();i++){
            if(temp[i-1]>=temp[i]){
                return false;
            }
            cout<<temp[i];
        }
        return true;
    }
};