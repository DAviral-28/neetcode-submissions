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
    int mps(TreeNode* root,int &m)
    {
        if(root==nullptr)
        return 0;
        int left=mps(root->left,m);
        int right=mps(root->right,m);
        int p=root->val + max(0,left)+max(0,right);
        m=max(m,p);
        return root->val+max(0,max(left,right));
    }
    void dfs(TreeNode* root,int &m)
    {
        if(root==nullptr)
        return;
        m=max(m,root->val);
        dfs(root->left,m);
        dfs(root->right,m);
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int m=INT_MIN;
        dfs(root,m);
        if(m<=0)
        return m;
        int w=mps(root,m);
        return m;
    }
};
