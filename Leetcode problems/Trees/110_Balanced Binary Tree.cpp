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
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right); 
        int diffHeight = abs(leftHeight - rightHeight);
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = diffHeight <= 1;
        
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};

// OPTIMISED APPROACH

class Solution {
public:
    bool isbalanced = true;
    int height(TreeNode* root){
        if(!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if(isbalanced && abs(lh-rh) > 1){
            isbalanced = false;
        }

        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};

