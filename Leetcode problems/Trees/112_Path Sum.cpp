//APPROACH 1

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
    bool solve(TreeNode* root, int targetSum, int sum){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            sum += root->val;
            if(sum == targetSum){
                return true;
            }
        }
        return solve(root->left,targetSum, sum + root->val) || solve(root->right,targetSum, sum + root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum); 
    }
};

//APPROACH 2

class Solution {
    void solve(TreeNode* root, int targetSum, int &sum, vector<vector<int>> &ans, vector<int> &path){
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

        solve(root->left,targetSum, sum, ans, path);
        solve(root->right,targetSum, sum, ans, path);

        path.pop_back();
        sum -= root->val;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root, targetSum, sum, ans, path);

        if(!ans.empty()){
            return true;
        } 
        else{
            return false;
        }
    }
};

//APPROACH 3    

class Solution {
   bool solve(TreeNode* root, int targetSum, int &sum){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            sum += root->val;
            if(sum == targetSum){
                return true;
            }
            //backtrack
            sum -= root->val;
        }
        sum += root->val;

       bool leftAns = solve(root->left,targetSum, sum);
       bool rightAns = solve(root->right,targetSum, sum);
    
       //backtrack
       sum -= root->val;

       return leftAns || rightAns;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return solve(root, targetSum, sum); 
    }
};