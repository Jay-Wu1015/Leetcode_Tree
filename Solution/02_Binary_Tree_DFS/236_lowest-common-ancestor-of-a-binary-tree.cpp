/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //走到leaf, 如果都沒有match, 回傳nullptr
        if(!root) return nullptr;
        //其中一個有match, 則回傳節點
        if(root==p || root==q) return root;
        
        //繼續走左右子樹
        TreeNode *left= lowestCommonAncestor(root->left, p, q);
        TreeNode *right= lowestCommonAncestor(root->right, p, q);

        //如果節點的左柚子樹都有match, 則表示此節點是左右子樹共同祖先, 若只有其中一子樹match，則表示該子樹節點包含p,q(其中一個為該子節點的子樹)
        if( left && right) return root;
        else if( left) return left;
        else return right;

    }
};
