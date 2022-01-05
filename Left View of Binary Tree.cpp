vector<int> leftView(Node *root)
{
   // Your code here
   queue<Node*>q;
   if(root)
   q.push(root);
   vector<int>ans;
   while(!q.empty())
   {
       int n=q.size();
       bool flag=true;
       while(n>0)
       {
           n--;
           Node* temp=q.front();
           q.pop();
           if(flag)
           {
               flag=false;
               ans.push_back(temp->data);
           }
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
       }
   }
   return ans;
}
