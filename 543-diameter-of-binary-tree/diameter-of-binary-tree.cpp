class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        int leftLevel = levels(root->left);
        int rightLevel = levels(root->right);
        return 1 +  max(leftLevel,rightLevel);
    }
    void helper(TreeNode* root, int &maxDia){
        if(root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia,dia);
        helper(root->left, maxDia);
        helper(root->right, maxDia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        helper(root, maxDia);
        return maxDia;
    }
};