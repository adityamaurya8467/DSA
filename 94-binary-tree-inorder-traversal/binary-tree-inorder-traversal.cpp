class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        InOrder(root, ans);
        return ans;
    }
};