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
    int ans=INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int temp=max(l,r)+1;
        int prev=l+r+1;
        //cout<<l<<" "<<r;
        //int prev=0;
        prev=max(prev,temp);
        ans=max(prev,ans);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x=solve(root);
        return ans-1;
    }
};