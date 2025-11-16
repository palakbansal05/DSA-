class Solution {
public:
    int helper(TreeNode* p, TreeNode* q){
        bool temp1=true,temp2=true;
        if(p->val!=q->val)
            return false;
        if((!p->right && !p->left) && (!q->right && !q->left))
            return true;
        if((p->right && !q-> left) || (p->left && !q->right) || (q->right && !p->left) || (q->left && !p->right))
            return false;
        if(p->right && q-> left )
            temp1=helper(p->right,q->left);
        if(p->left && q->right)
            temp2=helper(p->left,q->right);
        return temp1 && temp2;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return true;
        if((root->left && !root->right) || (root->right && !root->left))
            return false;
        return helper(root->left,root->right);         
    }
};