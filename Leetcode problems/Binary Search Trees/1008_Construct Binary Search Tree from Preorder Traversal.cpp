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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            int k = preorder[i];

            TreeNode* temp = root;
            TreeNode* newNode = new TreeNode(k);
            while(true){
                if(temp->val > k){
                    if(temp->left == NULL){
                        temp->left = newNode;
                        break;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else if(temp->val < k){
                    if(temp->right == NULL){
                        temp->right = newNode;
                        break;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
        }
        return root;
    }
};

// ANOTHER APPROACH

class Solution {
    TreeNode* solve(vector<int>& preorder, int &i, int min, int max){
        if(i >= preorder.size()){
            return nullptr;
        }
        TreeNode* root = nullptr;
        if(preorder[i]>min && preorder[i]<max){
            root = new TreeNode(preorder[i++]);
            root->left = solve(preorder, i, min, root->val);
            root->right = solve(preorder, i, root->val, max);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;

        int min =INT_MIN, max = INT_MAX;
        int i = 0;
        return solve(preorder, i, min, max);
    }
};