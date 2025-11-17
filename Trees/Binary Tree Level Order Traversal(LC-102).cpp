class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ans;
      if(root==NULL)
      return ans;
      queue<TreeNode*> q;
      q.push(root);
      q.push(NULL);
      vector<int> dummy;
      while(!q.empty())
      {
        TreeNode* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            ans.push_back(dummy);
            if(!q.empty())
            {
            q.push(NULL);
            dummy.clear();
            continue;
            }
            else
            break;
        }
        dummy.push_back(temp->val);
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
      }  
    return ans;
    }
};