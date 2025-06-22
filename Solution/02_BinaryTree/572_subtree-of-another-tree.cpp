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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //如果走完還有沒發現相同的節點，回傳false
        if(!root) return false;

        //由判斷式 isIdentical判斷節點數值，此節點的子樹大小是否相同，其中一個不同則回傳false
        if( isIdentical(root, subRoot)) return true;

        //root(較大方)先走往前移動左子樹或右子樹
        return  isSubtree(root->left, subRoot)||
                isSubtree(root->right, subRoot);
    }

private:
    bool isIdentical(TreeNode *s,TreeNode *t){
        
        //如果一起到nullptr, 表示長度相同，回傳true 
        if(!s && !t) return true;
        //如果任一方先到nullptr, 表示長度不同
        if(!s || !t) return false;

        //判斷節點val是否相同
        return s->val == t->val &&
                isIdentical(s->left, t->left)  &&
                isIdentical(s->right, t->right);
    }            

};
