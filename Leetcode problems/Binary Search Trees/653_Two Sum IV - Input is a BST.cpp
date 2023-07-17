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
    void inorder(TreeNode* root, vector<int> &inorderOfBst){
        if(!root) return;

        inorder(root->left, inorderOfBst);
        inorderOfBst.push_back(root->val);
        inorder(root->right, inorderOfBst);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderOfBst;
        inorder(root, inorderOfBst);

        int s = 0;
        int e = inorderOfBst.size()-1;

        while(s<e){
            int sum = inorderOfBst[s] + inorderOfBst[e];

            if(sum == k){
                return true;
            }
            else if(sum > k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};