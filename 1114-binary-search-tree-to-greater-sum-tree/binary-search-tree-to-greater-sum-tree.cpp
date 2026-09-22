class Solution {
public:
    int sum = 0;
    void InOrder(TreeNode* root){
        if(root == NULL) return;
        InOrder(root->right);
        root->val += sum;
        sum = root->val;
        InOrder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        InOrder(root);
        return root;
    }
};