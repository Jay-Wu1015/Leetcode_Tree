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
    int diameterOfBinaryTree(TreeNode* root) {
   
        int maxlength = 0;
        int maxleaflength = 0;

        leaflength(root, maxleaflength, maxlength);

        return maxlength;

    }
private: 
    int leaflength(TreeNode *root, int &maxleaflength, int &maxlength){
        if(!root) return 0;

        int leftlength = leaflength(root -> left, maxleaflength, maxlength);
        int rightlength = leaflength(root -> right, maxleaflength, maxlength);
          
        //更新目前最長的Diameter tree
        maxlength=max( maxlength, leftlength + rightlength);
      
        //比較左右maxleaflength , 回傳較大者
        return maxleaflength= max(leftlength, rightlength)+1;
        
    }
};
