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
        if (root == NULL) return {};
        
        vector<vector<int>> result = {};
        vector<TreeNode*> queue = {root};
        bool leftright = true;
        while (queue.size() > 0 ){
            vector<TreeNode*> temp = {};
            vector<int> restemp = {};
            for (TreeNode *t: queue){
                restemp.push_back(t -> val);

                if (t -> left != NULL) temp.push_back(t -> left);
                if (t -> right != NULL) temp.push_back(t -> right);
            }
            queue = temp;
            if (leftright) result.push_back(restemp); 
            else {
                reverse(restemp.begin(),restemp.end());
                result.push_back(restemp);
            }
            leftright ^= 1;
            
        }
        return result;
        
        
    }
};
