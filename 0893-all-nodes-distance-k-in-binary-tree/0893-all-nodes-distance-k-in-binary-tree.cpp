/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*> &mpp)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                mpp[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                mpp[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mpp;
        solve(root,target,mpp);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        vector<int> ans;int level=0;
        while(!q.empty())
        {
            int size=q.size();
            if(level++==k) break;
            // level++;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&!vis[node->left])
                {
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right&&!vis[node->right])
                {
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(mpp[node]&&!vis[mpp[node]])
                {
                    vis[mpp[node]]=true;
                    q.push(mpp[node]);
                }
            }
            
        }
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};