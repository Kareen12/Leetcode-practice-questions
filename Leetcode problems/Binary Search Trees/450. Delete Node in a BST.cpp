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
    int maxVal(TreeNode* root) {
    if(!root) return -1;
    
    while(true){
        if(root->right == NULL){
            return root->val;
            // break;
        }
        else{
            root = root->right;
        }
    }
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(root->left && !root->right){
                TreeNode* child = root->left;
                delete root;
                return child;
            }
            else if(!root->left && root->right){
                TreeNode* child = root->right;
                delete root;
                return child;
            }
            else{
                int inorderPred = maxVal(root->left);
                root->val = inorderPred;
                root->left = deleteNode(root->left, inorderPred);
                return root;
            }
        }
        else if(key < root->val){
            root->left =  deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right =  deleteNode(root->right, key);
        }
        return root;
    }
};