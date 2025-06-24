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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return vector<int>{};
        }
    
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int currlength=que.size();
            ans.push_back(que.back()->val);

            for(int i=0; i<currlength; i++){
                TreeNode *node=que.front();
                que.pop();

                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                
            }
        }
        return ans;
    }
};
