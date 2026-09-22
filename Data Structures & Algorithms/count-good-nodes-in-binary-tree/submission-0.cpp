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
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int c=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* p=q.front().first;
                int v=q.front().second;
                q.pop();
                if(p->left)
                {
                    if(p->left->val>=v)
                    {
                        q.push({p->left,p->left->val});
                        c++;
                    }
                    else
                    q.push({p->left,v});
                }
                if(p->right)
                {
                    if(p->right->val>=v)
                    {
                        q.push({p->right,p->right->val});
                        c++;
                    }
                    else
                    q.push({p->right,v});
                }
            }
        }
        return c;
    }
};
