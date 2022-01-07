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
    bool valid(TreeNode* x,int mn=INT_MIN,int mx=INT_MAX){
        if(!x) return 1;
        if(x->val<=mn or x->val>=mx) return 0;
        return (valid(x->left,mn,x->val)&valid(x->right,x->val,mx));
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        map<int,TreeNode*>t;
        map<int,int>cnt;
        for(TreeNode* x: trees){
            if(x) t[x->val]=x,cnt[x->val]++;
            if(x->left) cnt[x->left->val]++;
            if(x->right) cnt[x->right->val]++;
        }
        for(auto x: cnt){
            if(x.second==1 and t.count(x.first)){
                TreeNode* ans = t[x.first];
                queue<TreeNode*>q;
                q.push(ans);
                while(q.size()){
                    TreeNode* f=q.front();
                    q.pop();
                    if(!(f->left) and !(f->right)){
                        if(t.count(f->val) and t[f->val]!=f){
                            f->left=t[f->val]->left;
                            f->right=t[f->val]->right;
                            t.erase(f->val);
                        }
                    }
                    if(f->left) q.push(f->left);
                    if(f->right) q.push(f->right);
                }
                if(valid(ans)&&t.size()==1) return ans;   // check if the BST is valid or not
            }
        }
        TreeNode *tmp = NULL;
        return tmp;
    }
};