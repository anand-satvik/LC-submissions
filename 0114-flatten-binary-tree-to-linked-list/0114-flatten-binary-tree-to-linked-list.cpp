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
    
    // void solve(TreeNode* root)
    // {
    //     if(root==NULL)
    //     return;
    //     solve(root->right);
    //     solve(root->left);
    //     root->right=prev;
    //     root->left=NULL;
    //     prev=root;

    // }
    void flatten(TreeNode* root) {
        // if(root==NULL) return;
        TreeNode* cur=root;
        // TreeNode* prev;
        while(cur!=NULL)
        {
            if(cur->left!=NULL)
            {
                TreeNode* prev=cur->left;
                while(prev->right)
                {
                    prev=prev->right;
                }
                prev->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
        // solve(root);
    }
};