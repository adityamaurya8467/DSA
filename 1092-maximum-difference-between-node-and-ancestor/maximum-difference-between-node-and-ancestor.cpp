class Solution {
public:
    int helper(TreeNode* root, int mn, int mx){
        if(root ==  NULL) return 0;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        int left = helper(root->left, mn, mx);
        int right = helper(root->right, mn, mx);
        return max(mx - mn , max(left, right));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL) return 0;
        return helper(root, root->val, root->val);
    }
};