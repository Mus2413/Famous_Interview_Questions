class Solution
{
    public:
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        if(root==NULL)
        return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int i=n;
            while(i>0)
            {
                Node* temp=q.front();
                q.pop();
                if(i==1)
                ans.push_back(temp->data);
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                i--;
                
            }
        }
        return ans;
        
    }
};



  // } Driver Code Ends