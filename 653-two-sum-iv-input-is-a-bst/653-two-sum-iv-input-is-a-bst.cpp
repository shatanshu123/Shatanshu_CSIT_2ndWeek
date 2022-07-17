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
    void sol(TreeNode* root,vector<int>& v){
        if(root==nullptr)return;
        v.push_back(root->val);
        if(root->left)sol(root->left,v);
        if(root->right)sol(root->right,v);
    }
    
    bool findTarget(TreeNode* root, int k) {
       unordered_map<int,int>m;
        vector<int>v;
        sol(root,v);
        if(v.size()==1)return 0;
         for(int i=0;i<v.size();i++)
         { if(m.find(k-v[i])!=m.end())return true;
         m[v[i]]++;
         }
return false;
    }
};