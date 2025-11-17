class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (int i = 0; i < descriptions.size(); i++) {
            int parentVal = descriptions[i][0];
            int childVal = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if (nodes.find(parentVal) == nodes.end())
                nodes[parentVal] = new TreeNode(parentVal);

            if (nodes.find(childVal) == nodes.end())
                nodes[childVal] = new TreeNode(childVal);

            if (isLeft == 1)
                nodes[parentVal]->left = nodes[childVal];
            else
                nodes[parentVal]->right = nodes[childVal];

            children.insert(childVal);
        }

        for (unordered_map<int, TreeNode*>::iterator it = nodes.begin(); it != nodes.end(); ++it) {
            if (children.find(it->first) == children.end())
                return it->second;
        }

        return nullptr;
    }
};
