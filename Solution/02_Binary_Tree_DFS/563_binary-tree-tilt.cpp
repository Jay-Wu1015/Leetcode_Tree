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
    int findTilt(TreeNode* root) {
        int sumofsubnode = 0;
        int sumoftilt = 0;
        findval(root, sumofsubnode, sumoftilt);

        return sumoftilt;
    }
private:
    int findval(TreeNode* root,int sumofsubnode, int &sumoftilt  ){
        if(!root) return 0;
        
        int leftval= findval(root->left, sumofsubnode, sumoftilt);
        int rightval= findval(root->right, sumofsubnode, sumoftilt );

        sumoftilt += abs(leftval-rightval);
        sumofsubnode=leftval+rightval;

        return root->val+sumofsubnode;

    }


    
};
