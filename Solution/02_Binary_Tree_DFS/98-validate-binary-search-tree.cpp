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
    bool isValidBST(TreeNode* root) {
        
        return dfs(root, LONG_MIN, LONG_MAX);
    }
private:
    bool dfs(TreeNode * node, long small, long large){

        if(!node) return true;
        //判斷 節點val 是否在 small, large 之間
        if(node->val <= small || node->val >= large) return false;

        //往左子樹走, 左子樹所有的點要 < root val        
        bool left = dfs (node->left, small, node->val);

        //往右子樹走, 右子樹所有的點要 > root val 
        bool right = dfs (node->right, node->val, large);

        //左右子樹都要滿足條件
        return left && right; 
    }
};
