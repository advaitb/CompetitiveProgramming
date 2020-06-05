 #define MIN(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _b : _a; })

int calculateDepth(struct TreeNode* root, int depth)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    
    if((root->left == NULL) && (root->right == NULL))
    {
           return depth;
    }
    depth+=1;
    return MIN(calculateDepth(root->left,depth),calculateDepth(root->right,depth));
       
}


int minDepth(struct TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return calculateDepth(root,1);
}
