class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
          return false;
        if(root->val==targetSum&&!root->left && !root->right)
          return true;
        bool leftAns=hasPathSum(root->left,targetSum-root->val);
        bool rightAns=hasPathSum(root->right,targetSum-root->val);
        return (leftAns|| rightAns);
    }
};