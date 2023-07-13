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
     TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int &postInd, int inStartInd, int inEndInd, int size, unordered_map<int, int> &mp){
        if(postInd >= size || inStartInd > inEndInd){
            return NULL;
        }

        int rootElement = postorder[postInd--];
        TreeNode* root = new TreeNode(rootElement);

        //finding rootElement in inorder vector
        int pos = mp[root->val];

        //isme pehle right ki call marni h
        root->right = solve(postorder, inorder, postInd, pos+1, inEndInd, size, mp);
        root->left =  solve(postorder, inorder, postInd, inStartInd, pos-1, size, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        // if(size == 1){
        //     TreeNode* root = new TreeNode(preorder[0]);
        //     return root;
        // }
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++){
            mp[inorder[i]] = i;
        }
        int postInd = size-1, inStartInd = 0, inEndInd = size-1;
        return solve(postorder, inorder, postInd, inStartInd, inEndInd, size, mp);
    }
};