vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int>ans;
	if(root==NULL)
	return ans;
	
	bool flag=true;
	deque<Node*>q;
	q.push_front(root);
	while(!q.empty())
	{
	    int n=q.size();
	    while(n>0)
	    {
	        if(!flag)
	        {
	            Node* temp=q.front();
	            q.pop_front();
	            ans.push_back(temp->data);
	            if(temp->right)
	            q.push_back(temp->right);
	            if(temp->left)
	            q.push_back(temp->left);
	            
	        }
	        else
	        {
	            Node* temp=q.back();
	            q.pop_back();
	            ans.push_back(temp->data);
	            if(temp->left)
	            q.push_front(temp->left);
	            if(temp->right)
	            q.push_front(temp->right);
	        }
	        n--;
	    }
	    flag=!flag;
	}
	return ans;
	
}