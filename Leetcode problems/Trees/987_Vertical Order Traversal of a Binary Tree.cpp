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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        // Map contains mpping from row->col->sare nodes. Sre nodes ko store karne ke liye multiset liya h kyoki wo similar values ko rakh leta h unlike set but sorted order me rakhta h jo hume cahiye according to the ques , just like set jo sorted order me values rakhta h
        map<int, map<int, multiset<int>> > mp; 
        // queue contains node and pair of its corresponding row and col
        queue<pair<TreeNode*, pair<int,int>> > q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first; //yaha se node mili
            //yaha se row or col ki value mili in form of pair
            auto rowCol = temp.second; 
            int &row = rowCol.first;
            int &col = rowCol.second;

            //map me row or col ke corresponding node dal di
            mp[col][row].insert(node->val);

            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right,{ row+1, col+1}});
            }
        }
        for(auto i: mp){
            vector<int> v;
            for(auto j: i.second){
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};