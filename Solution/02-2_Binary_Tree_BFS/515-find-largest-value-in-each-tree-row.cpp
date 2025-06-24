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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>{};

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            
            int currlen = que.size();
            int currmax = INT_MIN;
            
            for(int i=0; i < currlen; i++){
                
                TreeNode *node=que.front();
                que.pop();
                currmax= max(currmax, node->val);


                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ans.push_back(currmax);
        }

        return ans;
    }
};
