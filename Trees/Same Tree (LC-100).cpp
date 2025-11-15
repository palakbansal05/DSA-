//Recursive Solution

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //if both the nodes are NULL, then return true
        if(!p && !q)
            return true;

        //if either of the node is NULL and the other one is not, then return false
        if(!p && q || !q && p)
            return false;

        //
        if(p->val!=q->val)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};