void help(Node* root,vector<int>& v)
{
    //base case
    if(!root)
    return ;
    
    v.push_back(root->data);
    help(root->bottom,v);
    help(root->next,v);
}

Node *flatten(Node *root)
{
   vector<int> v;
   help(root,v);
   
   sort(v.begin(),v.end());
   
   for(auto it:v)
   cout<<it<<" ";
   
   return NULL;
}