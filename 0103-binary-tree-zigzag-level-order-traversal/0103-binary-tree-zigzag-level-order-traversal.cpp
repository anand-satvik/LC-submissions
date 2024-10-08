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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        vector<vector<int>> res;
        if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);bool flag=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                int index;
                
                if(node->left!=NULL)
                q.push(node->left);
                if(node->right!=NULL)
                q.push(node->right);
                if(flag==0) index=i;
                else index=size-i-1;
                level[index]=node->val;
                
            }
            flag=!flag;
            res.push_back(level);
        }
        return res;
    }
};