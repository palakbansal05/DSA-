//Time Complexity: O(n) where n is the number of nodes
// Worst case is when the tree is skewed

class Solution {
public:
    void solve(TreeNode* root, vector<int> &res){
        if(!root)
            return;
       //Calls the function with left subtree
        solve(root->left,res);
      //Calls the function with right subtree
        solve(root->right,res);
      //Push the value of the root in the resultant vector
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root,res);
        return res;
    }
};
