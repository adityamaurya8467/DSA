class Solution {
public:
    void helper(TreeNode* root, int sum, int  &ans){
        if(root == NULL) return;
        sum = sum * 10 + root->val;
        if(root->left == NULL && root->right == NULL) {
            ans += sum;
            return;
        }
        helper(root->left, sum , ans);
        helper(root->right, sum , ans);
    }
    int sumNumbers(TreeNode* root) {
        int  ans = 0;
        helper(root, 0, ans);
        return ans;
    }
};