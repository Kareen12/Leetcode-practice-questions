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
    void solve(TreeNode* root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> &path ){
            if(root == NULL){
                return;
            }
            if(root->left == NULL && root->right == NULL){
                path.push_back(root->val);
                sum += root->val;
                if(sum == targetSum){
                    ans.push_back(path);
                }
                path.pop_back();
                sum -= root->val;
                return;
            }

            path.push_back(root->val);
            sum += root->val;

            solve(root->left, targetSum, sum, ans, path);
            solve(root->right, targetSum, sum, ans, path);

            //bactracking bcoz by refrence pass kiya h
            path.pop_back();
            sum -= root->val;
        }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root, targetSum, sum, ans, path);
        return ans;
    }
};