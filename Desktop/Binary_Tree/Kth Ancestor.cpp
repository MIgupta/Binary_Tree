// Simple Order Approach Path sum
// Space O(n)

vector<int> ans;
void help(Node* root,int node,vector<int> temp)
{
    if(root==NULL)return;
    if(root->data==node)
    {
        temp.push_back(root->data);
        ans=temp;
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        temp.push_back(root->data);
        return;
    }
    else
    {
        temp.push_back(root->data);
        help(root->left,node,temp);
        help(root->right,node,temp);
        
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> temp;
    help(root,node,temp);
    // for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    if(ans.size()<=k)return -1;
    return ans[ans.size()-k-1];
    
}


// Recursive Space O(1)

int help(Node* root,int &k,int node)
{
    if(root==NULL)return -1;
    
    if(root->data==node)
    return root->data;
    int l=help(root->left,k,node);
    int r=help(root->right,k,node);
    
    if(l!=-1 && r==-1)
    {
        --k;
        if(k==0)
        {
            k=INT_MAX;
            return root->data;
        }
        return l;
    }
    else if(r!=-1 && l==-1)
    {
        --k;
        if(k==0)
        {
            k=INT_MAX;
            return root->data;
        }
        
        return r;
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans=help(root,k,node);
    if(k<=100 && k!=0)return -1;
    return ans;
}
