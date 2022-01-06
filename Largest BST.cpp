pair<pair<bool,int>,pair<int,int>> traverse(Node* root)
{
    if(!root)
    return {{1 , 0},{0 , 0}};
    
    if(!root->left && !root->right)
    return {{1 , 1} , {root->data , root->data}};
    
    pair<pair<bool,int>,pair<int,int>> p1=traverse(root->left);
    pair<pair<bool,int>,pair<int,int>> p2=traverse(root->right);
    
    bool left= (root->left) ? ((p1.second.second < root->data) ? 1 : 0) : 1;
    bool right= (root->right) ? ((p2.second.first > root->data) ? 1 : 0) : 1;
    
    int l=(root->left) ? p1.second.first : root->data;
    int r=(root->right) ? p2.second.second : root->data;
    
    if(p1.first.first && p2.first.first && left && right)
    return {{1 , p1.first.second + p2.first.second + 1} , {l , r}};
    
    return {{0 , max(p1.first.second , p2.first.second)} , {0 , 0}};
}
int largestBst(Node *root)
{
	return traverse(root).first.second;
}
