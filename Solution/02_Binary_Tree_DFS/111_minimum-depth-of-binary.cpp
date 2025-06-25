//create Github question
/*
Given the root of a binary tree, return the sum of all left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/
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
    int minDepth(TreeNode* root) {
        //確認是否為葉子點
        if( !root) return 0;
        //若非葉子點,繼續往左右子樹走
        int left = minDepth( root->left);
        int right = minDepth( root -> right);


        //比較左右兩個子樹有無下一個節點，避免只有單邊子樹有節點
        if(!(root->left)|| !(root->right) ){
            return right+left +1; 
        }

        //若兩邊子樹都有下一個節點，比較下方節點長度，回傳最短者+本身節點
        return min(left, right)+1;

        
    }

};
