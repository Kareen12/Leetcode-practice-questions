// BRUTE FORCE APPROACH

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
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        
        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = height(root->left) + height(root->right);
        
        return max(opt1, max(opt2, opt3));
        
    }
};

// OPTIMAL APPROACH USING PAIR

class Solution {
    pair<int, int> solve(TreeNode* root){
        if(root == NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        // int opt3 = height(root->left) + height(root->right);

        int opt1 = leftAns.first;
        int opt2 = rightAns.first;
        int opt3 = leftAns.second + rightAns.second;

        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(leftAns.second, rightAns.second) + 1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        // if(root == NULL){
        //     return 0;
        // }
        
        return solve(root).first;
        
    }
};

// OPTIMAL APPROACH WITH BETTER SPACE COMPLEXITY

class Solution {
public:
    int diameter = 0;
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftAns = height(root->left);
        int rightAns = height(root->right);
        
        int currDiameter = leftAns + rightAns;
        diameter = max(diameter, currDiameter);
        int ans = max(leftAns, rightAns) + 1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        height(root);
        return diameter;
        
    }
};