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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return vector<vector<int>>{};

        vector<vector<int>> ans;
        queue<TreeNode*> que;

        bool isL2R= true;

        que.push(root);

        while(!que.empty()){
            
            int currlen= que.size();
            vector <int> level(currlen);

            for(int i=0; i<currlen; i++){
                
                TreeNode *node=que.front();
                que.pop();

                int index = isL2R? i : currlen-1-i;
                level[index] = node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            
            ans.push_back(level);
            isL2R= !isL2R;
            
        }

        return ans;

        return ans;
    }
};
