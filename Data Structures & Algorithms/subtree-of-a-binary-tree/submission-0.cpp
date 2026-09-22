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
    bool check(TreeNode* root1,TreeNode* root2)
    {
        if(root1==nullptr && root2==nullptr)
        return true;
        if(root1==nullptr || root2==nullptr)
        return false;
        if(root1->val!=root2->val)
        return false;
        return check(root1->left,root2->left) && check(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p=q.front();
            q.pop();
            if(p->val==subRoot->val)
            {
                if(check(p,subRoot))
                return true;
            }
            if(p->left)
            q.push(p->left);
            if(p->right)
            q.push(p->right);
        }
        return false;
    }
};
