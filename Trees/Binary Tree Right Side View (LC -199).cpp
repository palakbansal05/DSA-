//Time complexity: O(n) where n is the number of nodes in the tree
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            TreeNode*curr=q.front();
            res.push_back(curr->val);
            int n=q.size();
            for(int i=0;i<n;i++){
                curr=q.front();
                q.pop();
                if(curr->right)
                    q.push(curr->right);
                if(curr->left)
                    q.push(curr->left);
            }
        }
        return res;
    }
};
