class Solution {
public:
    void InOrder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        InOrder(root->left, ans);
        ans.push_back(root->val);
        InOrder(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        InOrder(root, ans);
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] <= ans[i-1]) return false;
        }
        return true;
    }
};