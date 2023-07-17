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
    bool solve(TreeNode* root, long lb, long ub){
        if(!root) return true;

        if(root->val >lb && root->val < ub){
            bool leftAns = solve(root->left, lb, root->val);
            bool rightAns = solve(root->right, root->val, ub);
            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }
};