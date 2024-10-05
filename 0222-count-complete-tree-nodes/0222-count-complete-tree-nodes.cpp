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
    int findL(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->left;
        }
        return h;
    }
    int findR(TreeNode* node)
    {
        int h=0;
        while(node)
        {
            h++;
            node=node->right;
        }
        return h;
    }
    int solve(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh=findL(root);
        int rh=findR(root);
        if(lh==rh) return (1<<lh)-1;
        else
        return 1+solve(root->left)+solve(root->right);
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};