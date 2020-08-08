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
    int helperc(TreeNode* node, int target){
    if (node == NULL) return 0;
    int temp = helperc(node->left,target - node->val)+ helperc(node->right,target - node->val);
    return (target == node->val)? 1 + temp:temp;
    }
    
    int helper(TreeNode* node, int target){
    if (node == NULL) return 0;
    int temp = helperc(node->left,target - node->val)+ helperc(node->right,target - node->val) + helper(node-> left,target)+ helper(node->right,target);
    return (target == node->val)? 1 + temp:temp;
    }
    
    int pathSum(TreeNode* root, int sum) {        
        return helper(root,sum);
    }
};
