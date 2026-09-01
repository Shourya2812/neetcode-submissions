class Solution {
public:
    int dfs(TreeNode* root, int maxVal) {

        if (root == NULL)
            return 0;

        int count = 0;

        if (root->val >= maxVal)
            count = 1;

        maxVal = max(maxVal, root->val);

        count += dfs(root->left, maxVal);
        count += dfs(root->right, maxVal);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};