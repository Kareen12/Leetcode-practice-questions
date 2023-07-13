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
    unordered_map<string, int> mp;
    string solve(TreeNode* root, vector<TreeNode*> &ans){
        if(!root) return "N";

        string curr =  to_string(root->val);
        string l = solve(root->left, ans);
        string r = solve(root->right, ans);

        string s = curr + "," + l + "," + r;

        if(mp.find(s) != mp.end()){
            if(mp[s] == 1){
                ans.push_back(root);
                mp[s]++;
            }
        }
        else{
            mp[s] = 1;
        }
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        solve(root, ans);
        return ans;
    }
};