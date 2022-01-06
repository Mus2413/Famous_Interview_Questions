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
    int prest;
int findx(vector<int> in,int st,int n,int x)
{
    
    for(int i=st;i<=n;i++)
    {
        if(in[i]==x)
        return i;
    }
    return -1;
    
}
TreeNode* treeconstruct(vector<int> in,vector<int> pre,int inst,int inend,int n)
{
    if(prest>=n)
    {
        return NULL;
    }
    int x=pre[prest];
    prest++;
    int index=findx(in,inst,inend,x);
    TreeNode* temp=new TreeNode(x);
    if(inst<index)
    temp->left=treeconstruct(in ,pre,inst,index-1,n);
    if(index<inend)
    temp->right=treeconstruct(in ,pre,index+1,inend,n);
    return temp;
    
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
         prest=0;
        int n=in.size();
    TreeNode* root=treeconstruct(in ,pre,0,n-1,n);
    return root;
    }
};