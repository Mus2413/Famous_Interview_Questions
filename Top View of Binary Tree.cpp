

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
     map<int,int>mp;
     if(root==NULL)
     return ans;
     queue<pair<Node*,int>>q;
     q.push({root,0});
     while(!q.empty())
     {
         int n=q.size();
         while(n>0){
         Node* temp=q.front().first;
         int x=q.front().second;
         q.pop();
         if(mp.find(x)==mp.end())
         {
             mp[x]=temp->data;
         }
         if(temp->left)
         {
             q.push({temp->left,x-1});
         }
         if(temp->right)
         {
             q.push({temp->right,x+1});
         }
         n--;
         }
         
     }
     for(auto x: mp)
     {
         ans.push_back(x.second);
     }
     return ans;

    }

};
