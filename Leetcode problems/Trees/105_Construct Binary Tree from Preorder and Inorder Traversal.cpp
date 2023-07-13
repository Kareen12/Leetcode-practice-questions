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
    int findRootElement(int rootElement,  vector<int>& inorder, int n){
        for(int i=0; i<n; i++){
            if(inorder[i] == rootElement){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preInd, int inStartInd, int inEndInd, int size){
        if(preInd >= size || inStartInd > inEndInd){
            return NULL;
        }

        int rootElement = preorder[preInd++];
        TreeNode* root = new TreeNode(rootElement);

        //finding rootElement in inorder vector
        int pos = findRootElement(rootElement, inorder, size);

        //left and right recursion sambhal lega
        root->left =  solve(preorder, inorder, preInd, inStartInd, pos-1, size);
        root->right = solve(preorder, inorder, preInd, pos+1, inEndInd, size);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        // if(size == 1){
        //     TreeNode* root = new TreeNode(preorder[0]);
        //     return root;
        // }
        int preInd = 0, inStartInd = 0, inEndInd = size-1;
        return solve(preorder, inorder, preInd, inStartInd, inEndInd, size);
    }
};

// OPTIMISED APPROACH

class Solution {
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &preInd, int inStartInd, int inEndInd, int size, unordered_map<int, int> &mp){
        if(preInd >= size || inStartInd > inEndInd){
            return NULL;
        }

        int rootElement = preorder[preInd++];
        TreeNode* root = new TreeNode(rootElement);

        //finding rootElement in inorder vector
        int pos = mp[root->val];

        //left and right recursion sambhal lega
        root->left =  solve(preorder, inorder, preInd, inStartInd, pos-1, size, mp);
        root->right = solve(preorder, inorder, preInd, pos+1, inEndInd, size, mp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        // if(size == 1){
        //     TreeNode* root = new TreeNode(preorder[0]);
        //     return root;
        // }
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++){
            mp[inorder[i]] = i;
        }
        int preInd = 0, inStartInd = 0, inEndInd = size-1;
        return solve(preorder, inorder, preInd, inStartInd, inEndInd, size, mp);
    }
};