/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        //判斷root1, root2 當前節點是否為空, root1 為空 後續 則為root2, 反之
        if(!root1) return root2;
        if(!root2) return root1;

        //若兩root1, root2 皆有值，建立新節點
        TreeNode *merge = new TreeNode(root1->val + root2->val);
        
        //新節點持續向左右子樹前進
        merge->left=mergeTrees(root1->left, root2->left);
        merge->right=mergeTrees(root1->right, root2->right);

        return merge;

    }
};
