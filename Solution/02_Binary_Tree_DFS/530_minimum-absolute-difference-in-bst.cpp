/*
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
    int getMinimumDifference(TreeNode* root) {
      
        int minDiff=1000000;
        TreeNode *pre = nullptr;

        inorder(root, pre, minDiff);
        return minDiff;
    }

    void inorder(TreeNode * root, TreeNode *&pre, int &minDiff){

        if(!root) return;

        inorder(root->left, pre, minDiff );

            if(pre){
                minDiff=min(minDiff, abs(root->val-pre->val));
            }
            pre = root;
        
        inorder(root->right, pre, minDiff);

        
    }


};
