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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int foundNull = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            // agar koi null node mil jati h to uske baad koi non null node ni milno chahiye for it to be a complete binary tree 
            if(foundNull && temp!=NULL){
                return false;
            }
            if(temp == NULL){
                foundNull = 1;
                continue;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        return true;
    }
};